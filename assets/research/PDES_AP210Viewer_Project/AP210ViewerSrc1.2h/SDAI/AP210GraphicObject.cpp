// AP210GraphicObject.cpp: implementation of the AP210GraphicObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AP210GraphicObject.h"
#include "../PWBDataBase.h"
#include "..\OpenGL\Tess.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
GLfloat AP210GraphicObject::TransparentAlpha = 0.3;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int AP210GraphicObject::BaseglName = 0;

AP210GraphicObject::AP210GraphicObject(PWBDataBase *PWB):
AP210Object(PWB) {
   glName = 0;
   ReDrawStatus = 0;
   Selected = 0;
   CapDisplayList = 0;
   SideDisplayList = 0;
   setTransparency(FALSE);
   }

AP210GraphicObject::~AP210GraphicObject() {

   }
int AP210GraphicObject::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return AP210Object::DynamicType(ID);
   }
#ifdef INSTANCEOF
AP210GraphicObject *AP210GraphicObject::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(AP210GraphicObject *)s;
   return 0;
   }
AP210GraphicObject *AP210GraphicObject::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(AP210GraphicObject *)s;
   return 0;
   }
#endif
void AP210GraphicObject::UpdateAllViews(CView * pSender, LPARAM lHint, CObject * pHint) {
   DataBase->UpdateAllViews(pSender, lHint, pHint);
   }

void AP210GraphicObject::setReDrawStatus(int status) {
   ReDrawStatus = status;
   }
//////////////////////////////////
// Implementation
void AP210GraphicObject::TracePoints() {
   AP210ObjectListItor itor(&Points);
   AP210Point *p;
   while((p = (AP210Point *)itor.Next()) != NULL) {
      TRACE("(%f, %f) ", p->X, p->Y);
      }
   TRACE("\r\n");  
   }
/*--------------------------------------------------------------------------
 *
 * AP210GraphicObject.Render()
 *
 * Render the OpenGL display lists for the component, shading the sides
 * and highlighting if selected.
 */
// Check out the calls to this function the color names aren't correct.
void AP210GraphicObject::Render(double red, double green, double blue) {
   static double selectcolor = 0.9;
   static double sidecolor = 0.5; //0.3;
   GLint render_mode;

   // process cases where Alpha is less than 1.0
   // eg. invisible or transparent items
   if (Alpha < 1.0 ) {
      // No need to draw invisible objects.
      if (Alpha == 0.0) {
         return;
         }
     //  Don't consider for selection transparent items.
      glGetIntegerv(GL_RENDER_MODE, &render_mode);

      if (render_mode == GL_SELECT) {
         return;
         }
      }
   // Check to see if display lists need updating
   if (getReDrawStatus()) {
      setReDrawStatus (0);
      ReDraw();
      }
   // darken the colors if selected
   if (Selected) {
      red = selectcolor;
      blue = selectcolor;
      green = selectcolor;
      }
   // set the color of the caps
   glColor4f(red, green, blue, Alpha);OutputGlError("A glColor4f(red, green, blue, Alpha);");

   // Load the name for selection
   glLoadName(getglName());OutputGlError("glLoadName(GetglName())");

   // render the caps
   RenderCaps();

   // generate darker colors for the sides
   if (red != 0.0) {
      red = red - sidecolor;
      }
   if (blue != 0.0) {
      blue = blue - sidecolor;
      }
   if (green != 0.0) {
      green = green - sidecolor;
      }
   // set the darkened color for the sides
   glColor4f(red, green, blue, Alpha); OutputGlError("B glColor4f(red, green, blue, Alpha);");

   // render the sides
   RenderSides();
   }
void AP210GraphicObject::RenderCaps() {
   glPushMatrix();
   glCallList(getCapDisplayList());OutputGlError("glCallList(CapDisplayList)");
   }

void AP210GraphicObject::RenderSides() {
   glCallList(getSideDisplayList());OutputGlError("glCallList(SideDisplayList)");
   glPopMatrix();
   }
//
//	OutputGlError
//
void AP210GraphicObject::OutputGlError(char* label) {
	GLenum errorno = glGetError() ;
	if (errorno != GL_NO_ERROR) {
		TRACE("AP210GraphicObject: %s had error: #(%d) %s\r\n", label, errorno, gluErrorString(errorno)) ;
#if 0
		while(errorno != GL_NO_ERROR) {
			errorno = glGetError();
		TRACE("   %s had error: #(%d) %s\r\n", label, errorno, gluErrorString(errorno)) ;
 		   }
#endif
	   }
   }
/*--------------------------------------------------------------------------
 *
 * AP210GraphicObject::ReDraw()
 *
 * Rebuild the OpenGL display lists for the component
 * after a change.
 */
void AP210GraphicObject::ReDraw(double Z, double Base) {
    // calculate top
   double z = Z + Base;

   // Delete the existing caps display list
   glDeleteLists(getCapDisplayList(), 1); OutputGlError("glDeleteLists(CapDisplayList, 1)");

   // Create the caps display list
   CapsDisplayList(z, Base);

   // Delete the existing sides display list
   glDeleteLists(getSideDisplayList(), 1); OutputGlError("glDeleteLists(SideDisplayList, 1)");

   // Create the sides display list
   SidesDisplayList(z, Base);
   }
/*--------------------------------------------------------------------------
 *
 * AP210GraphicObject::Draw()
 *
 * Build the OpenGL display lists for the component.
 */
void AP210GraphicObject::Draw(double Z, double Base) {
    // calculate top
   double z = Z + Base;

   // Generate the CapDisplayList indice
   CapDisplayList = glGenLists(1); OutputGlError("A glGenLists(1);");

   // Create the caps display list
   CapsDisplayList(z, Base);

   // Generate the SideDisplayList indice
   SideDisplayList = glGenLists(1); OutputGlError("B glGenLists(1);");

   // Create the sides display list
   SidesDisplayList(z, Base);
   }
void AP210GraphicObject::CapsDisplayList(double Z, double Base) {
   AP210Point *p;
   AP210ObjectListItor itor(&Points);
   // Prepare the CapDisplayList
   glNewList(CapDisplayList, GL_COMPILE);

   // Draw the top of the component
   gluTessBeginPolygon(tobj, NULL);
   gluTessBeginContour(tobj);
   itor.Reset();
   while((p = (AP210Point *)itor.Next()) != NULL) {
      // This is a major memory leak. This data needs to be in an
      // OpenGL Data structure. Add the v's to this class 
      // this could be tv in AP210Point.
      GLdouble *v = (GLdouble *)calloc(1, 3*sizeof(GLdouble));
	   v[0] = p->X;
	   v[1] = p->Y;
	   v[2] = Z;
	   gluTessVertex(tobj, v, v);
      }
   gluTessEndContour(tobj);
   gluTessEndPolygon(tobj);

   // Draw the bottom of the component
   gluTessBeginPolygon(tobj, NULL);
   gluTessBeginContour(tobj);
   itor.Reset();
   while((p = (AP210Point *)itor.Next()) != NULL) {
      // This is a major memory leak. This data needs to be in an
      // OpenGL Data structure.  Add the v's to this class
      // this could be bv in AP210Point.
       GLdouble *v = (GLdouble *)calloc(1, 3*sizeof(GLdouble));
	   v[0] = p->X;
	   v[1] = p->Y;
	   v[2] = Base;
	   gluTessVertex(tobj, v, v);
      }         
   gluTessEndContour(tobj);
   gluTessEndPolygon(tobj);

   // end the Cap DisplayList
   glEndList();
   }

void AP210GraphicObject::SidesDisplayList(double Z, double Base) {
   AP210Point *p;
   AP210ObjectListItor itor(&Points);

   // Prepare the SideDisplayList
   glNewList(SideDisplayList, GL_COMPILE);

   // Draw the sides of the component
   glBegin(GL_QUAD_STRIP);
   itor.Reset();
   while((p = (AP210Point *)itor.Next()) != NULL) {
      glVertex3f(p->X, p->Y, Base);
      glVertex3f(p->X, p->Y, Z);
	   }
   itor.Reset();
   if ((p = (AP210Point *)itor.Next()) != NULL) {
      glVertex3f(p->X, p->Y, Base);
      glVertex3f(p->X, p->Y, Z);
	   }
   glEnd();

   // end the Side DisplayList
   glEndList();

   }
/////////////////
// Selection functions
void AP210GraphicObject::Select() {
   Selected = 1;
   }
int AP210GraphicObject::Select(GLuint ptr) {
  if (ptr == getglName()) {
     Selected = 1;
     }
   return(Selected);
   }
int AP210GraphicObject::isSelected() {
   return(Selected);
   }
void AP210GraphicObject::unSelect() {
   Selected = 0;
   }

int AP210GraphicObject::getReDrawStatus() {
   return ReDrawStatus;
   }

GLuint AP210GraphicObject::getCapDisplayList() {
#ifdef VERBOSE
if (CapDisplayList == NULL)
TRACE("WARNING: CapDisplayList: 0x%08x\r\n", CapDisplayList);
#endif
   return CapDisplayList;
   }

GLuint AP210GraphicObject::getSideDisplayList() {
#ifdef VERBOSE
if (SideDisplayList == NULL)
TRACE("WARNING: SideDisplayList: 0x%08x\r\n", SideDisplayList);
#endif
   return SideDisplayList;
   }
BOOL AP210GraphicObject::getTransparency() {
   return Transparent;
   }

void AP210GraphicObject::setTransparency(BOOL transparency) {
   Transparent = transparency;

   if (Transparent) {
      // set alpha to transparent value.
      Alpha = TransparentAlpha;
      }
   else {
      // set alpha to opaque value.
      Alpha = 1.0;
      }
   }
