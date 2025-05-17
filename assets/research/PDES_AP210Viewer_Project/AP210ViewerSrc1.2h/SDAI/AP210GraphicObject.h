// AP210GraphicObject.h: interface for the AP210GraphicObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AP210GRAPHICOBJECT_H__2D91EDA1_F29A_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_AP210GRAPHICOBJECT_H__2D91EDA1_F29A_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AP210Object.h"
#include "AP210ObjectList.h"

class AP210GraphicObject : public AP210Object {
   friend class CAP210ViewerView; // to get points for size of board to scale.
   friend class PWBDataBase; // to set Alpha in updateMountingRestrictionAreas().
   protected:
      enum {typeID = baseID + 10};

   public:
      AP210GraphicObject(PWBDataBase *PWB);
      virtual ~AP210GraphicObject();

      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static AP210GraphicObject *DirectInstanceOf(AP210Object *);
      static AP210GraphicObject *InstanceOf(AP210Object *);
#endif
   // implementation
   private:

      // modification
 	   int ReDrawStatus;

      // selection
	   int Selected;

      // OpenGL display lists used to render and determine selection.
      GLuint CapDisplayList;
      GLuint SideDisplayList;

   protected:
      // 2D shape
      AP210ObjectList Points;

      // name used for selection
      GLuint glName;

      // control on transparency of graphics
      BOOL Transparent;

      static int BaseglName;

   private:
	   virtual void SidesDisplayList(double Z, double Base);
	   virtual void CapsDisplayList(double Z, double Base);

   protected:
      SdaiAppInstance ShapeRepRef; // object's shape_representation

      GLfloat Alpha;
      GLuint getglName() { return glName; };
      virtual void RenderCaps();
      virtual void RenderSides();

      // modification
      virtual void setReDrawStatus(int status = 1);
	   virtual int getReDrawStatus();

      virtual void OutputGlError(char* label) ; // OPENGL function to display OpenGL errors using TRACE

   public:
      static GLfloat TransparentAlpha;
      virtual BOOL getTransparency();
      void setTransparency(BOOL transparency);
      // Selection functions
      virtual void Select();
      virtual int Select(GLuint ptr);
      virtual int isSelected();
      virtual void unSelect();

      // Drawing functions
      virtual GLuint getSideDisplayList();
      virtual GLuint getCapDisplayList();
      void TracePoints(); // debug
      virtual void Draw(double Z = 0.0, double Base = 0.0);
      virtual void ReDraw(double Z = 0.0, double Base = 0.0);
      virtual void Render(double red, double green, double blue);
      virtual void UpdateAllViews(CView* pSender, LPARAM lHint = 0L, CObject* pHint = NULL );
   };

#endif // !defined(AFX_AP210GRAPHICOBJECT_H__2D91EDA1_F29A_11D3_8A99_0080AD428934__INCLUDED_)
