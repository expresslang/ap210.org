// AP210ViewerView.cpp : implementation of the CAP210ViewerView class
//

#include "stdafx.h"

#include "AP210Viewer.h"

#include "AP210ViewerDoc.h"
#include "AP210ViewerView.h"
#include "Sdai/NonPlatedThruHole.h"
#include "Sdai/PackagedComponent.h"
#include "Sdai/MountingRestrictionArea.h"
#include "OpenGL/MatrixUtilities.h"

// GUI
#include "ComponentPlacementRestriction.h"

#include "InterconnectModulePropertiesSheet.h"
#include "ComponentPropertiesSheet.h"
#include "ComponentDefinitionSheet.h"

#include "NonPlatedThruHoleSheet.h"
#include "ComponentPlacementRestrictionAreaSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// selection stuff
#define MAXSELECT 100000
GLuint selectBuf[MAXSELECT];

// Notes:
//
// Since the polygons for the components aren't rendered with regard to
// orientation (i.e. clockwise or counterclockwise) culling of polygons
// by front or back facing must not be done. 

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerView

IMPLEMENT_DYNCREATE(CAP210ViewerView, CView)

BEGIN_MESSAGE_MAP(CAP210ViewerView, CView)
	//{{AFX_MSG_MAP(CAP210ViewerView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEWHEEL()
	ON_WM_RBUTTONDBLCLK()
	ON_COMMAND(ID_COMPONENT_RESTRICTION_AREA, OnComponentRestrictionArea)
	ON_COMMAND(ID_PRIMARY_SURFACE, OnPrimarySurface)
	ON_COMMAND(ID_SECONDARY_SURFACE, OnSecondarySurface)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerView construction/destruction

CAP210ViewerView::CAP210ViewerView() {
TRACE("IN CAP210ViewerView::CAP210ViewerView()\r\n");
   // TODO: add construction code here
   // Palette Initialization
   m_pPal = NULL ;

   // Centering Initialization
   DeltaX = 0.0;
   DeltaY = 0.0;

   // Perspective Initialization
   glFovy = 30.0;
   glNear = 1.0;
   glFar = 100.0;

   // start by viewing the primary surface
   orientPrimarySurface();
   }

CAP210ViewerView::~CAP210ViewerView()
{
	// TODO: add destructor code here
	if (m_pPal) delete m_pPal ;
}

BOOL CAP210ViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

    // MTK: Here is where you should initialize opengl for
    //      this window.
    // OpenGL
	TRACE0("CAP210ViewerView::PreCreateWindow\r\n") ;
    // OpenGL can't render to child or sibling windows so clip them.
  	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN; 

	return CView::PreCreateWindow(cs);
}

//
// OnInitialUpdate
//
void CAP210ViewerView::OnInitialUpdate() {
	TRACE0("CAP210ViewerView::OnInitialUpdate\r\n") ;	
	// TODO: Add your specialized creation code here

#ifdef TRACKBALL
   // setup trackball
   trackball(curquat, 0.0, 0.0, 0.0, 0.0);
   trackball(lastquat, 0.0, 0.0, 0.0, 0.0);
#endif
   // Setup Geometry
	PrepareScene();

   // set up distance from board.
   set_eyeZ();

	CView::OnInitialUpdate();
   }


/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerView drawing
void CAP210ViewerView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) {
   CView::OnPrepareDC(pDC, pInfo);
   // TODO: Add your specialized code here and/or call the base class
   // Make the HGLRC current
   // for this to work properly on NT I believe we need to manipulate
   // the palette here also see OnDraw().
#if 0
   if (pInfo == NULL) {
      BOOL bResult = wglMakeCurrent(pDC->m_hDC, m_hrc);
      if (!bResult) {
// error created in print-preview.
//wglMakeCurrent Failed in CAP210ViewerView::OnDraw The pixel format is invalid.
#if 1
         LPVOID lpMsgBuf;

         FormatMessage( 
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            GetLastError(),
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR) &lpMsgBuf,
            0,
            NULL 
            );

// Display the string.
//MessageBox( NULL, lpMsgBuf, "GetLastError", MB_OK|MB_ICONINFORMATION );
         TRACE("wglMakeCurrent Failed in CAP210ViewerView::OnPrepareDC %s\r\n", lpMsgBuf ) ;
         TRACE("pInfo: 0x%08x\n", pInfo);

         // Free the buffer.
         LocalFree( lpMsgBuf );
 
#else
         TRACE("wglMakeCurrent Failed in CAP210ViewerView::OnPrepareDC %x\r\n", GetLastError() ) ;
#endif
         }
      }	
#endif
   }
void CAP210ViewerView::OnDraw(CDC* pDC) {
	CAP210ViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
#ifdef VERBOSE
	TRACE0("CAP210ViewerView::OnDraw\r\n") ;
#endif
	// TODO: add draw code for native data here

    // Select the palette.
    CPalette* ppalOld = NULL;
	if (m_pPal) {
    	ppalOld = pDC->SelectPalette(m_pPal, 0);
    	pDC->RealizePalette();
  	}
      BOOL bResult = wglMakeCurrent(pDC->m_hDC, m_hrc);
      if (!bResult) {
// error created in print-preview.
//wglMakeCurrent Failed in CAP210ViewerView::OnDraw The pixel format is invalid.
#if 1
         LPVOID lpMsgBuf;

         FormatMessage( 
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            GetLastError(),
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR) &lpMsgBuf,
            0,
            NULL 
            );

// Display the string.
//MessageBox( NULL, lpMsgBuf, "GetLastError", MB_OK|MB_ICONINFORMATION );
         TRACE("wglMakeCurrent Failed in CAP210ViewerView::OnPrepareDC %s\r\n", lpMsgBuf ) ;

         // Free the buffer.
         LocalFree( lpMsgBuf );
 
#else
         TRACE("wglMakeCurrent Failed in CAP210ViewerView::OnPrepareDC %x\r\n", GetLastError() ) ;
#endif
         }
	// Draw	Assembly
	DrawScene();

	//Swap Buffers
	SwapBuffers(pDC->m_hDC) ;
 
    // select old palette if we altered it
    if (ppalOld) {
       pDC->SelectPalette(ppalOld, 0); 
       }
	wglMakeCurrent(NULL, NULL) ;
   }

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerView printing
// It is possible that all these print functions can be removed.
// currently having a problem with the pixel format of the 
// print preview device context.
BOOL CAP210ViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAP210ViewerView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo){
   // TODO: add extra initialization before printing
   //
   // Create a rendering context.
   //
   p_hrc = wglCreateContext(pDC->m_hDC);
   if (!p_hrc) {
      TRACE("CAP210ViewerView::OnBeginPrinting wglCreateContext Failed %x\r\n", GetLastError()) ;
      }
   }

void CAP210ViewerView::OnPrint(CDC* pDC, CPrintInfo* pInfo) {
	// TODO: Add your specialized code here and/or call the base class
    BOOL bResult = wglMakeCurrent(pDC->m_hDC, m_hrc);
	if (!bResult)
	{
		TRACE("CAP210ViewerView::OnPrint wglMakeCurrent Failed %x\r\n", GetLastError() ) ;
		return ;
	}
	// Call to base class.
	CView::OnPrint(pDC, pInfo);
   }

void CAP210ViewerView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add cleanup after printing
	wglMakeCurrent(NULL,NULL) ; 
	if (p_hrc) 
	{
		wglDeleteContext(p_hrc) ;
		p_hrc = NULL ;
	}		
}

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerView diagnostics

#ifdef _DEBUG
void CAP210ViewerView::AssertValid() const
{
	CView::AssertValid();
}

void CAP210ViewerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAP210ViewerDoc* CAP210ViewerView::GetDocument() // non-debug version is inline
{
//	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAP210ViewerDoc)));
	return (CAP210ViewerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerView message handlers

int CAP210ViewerView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
    TRACE0("CAP210ViewerView::OnCreate\r\n");

	// OpenGL 
    CClientDC dc(this) ;
	//
	// Fill in the Pixel Format Descriptor
	//
    PIXELFORMATDESCRIPTOR pfd ;
	memset(&pfd,0, sizeof(PIXELFORMATDESCRIPTOR)) ;

    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);   
    pfd.nVersion = 1 ;                           // Version number
	pfd.dwFlags =  PFD_DOUBLEBUFFER |            // Use double buffer
	               PFD_SUPPORT_OPENGL |          // Use OpenGL
//                  PFD_DRAW_TO_BITMAP |          // from OpenGL printing example.
	               PFD_DRAW_TO_WINDOW ;          // Pixel format is for a window.
	pfd.iPixelType = PFD_TYPE_RGBA ;
    pfd.cColorBits = 24;                         // 8-bit color
	pfd.cDepthBits = 32 ;					   	 // 32-bit depth buffer
    pfd.iLayerType = PFD_MAIN_PLANE ;            // Layer type

    int nPixelFormat = ChoosePixelFormat(dc.m_hDC, &pfd);
	if (nPixelFormat == 0)
	{
		TRACE("ChoosePixelFormat Failed %d\r\n",GetLastError()) ;
		return -1 ;
	}
	TRACE("Pixel Format %d\r\n", nPixelFormat) ;

    BOOL bResult = SetPixelFormat(dc.m_hDC, nPixelFormat, &pfd);
	if (!bResult)
	{
		TRACE("SetPixelFormat Failed %d\r\n",GetLastError()) ;
		return -1 ;
	}
	
	//
    // Create a rendering context for OpenGl
    //
    m_hrc = wglCreateContext(dc.m_hDC);
	if (!m_hrc)
	{
		TRACE("wglCreateContext Failed %x\r\n", GetLastError()) ;
		return -1;
	}

	// Create the palette
TRACE0("About to CreateRGBPalete\r\n");
	CreateRGBPalette(dc.m_hDC) ;	
TRACE0("Done With CreateRGBPalete\r\n");
#ifdef GL_EXT_polygon_offset
  /* check for the polygon offset extension */
  if (glutExtensionSupported("GL_EXT_polygon_offset")) {
    polygonOffsetVersion = EXTENSION;
    glPolygonOffsetEXT(-0.1, -0.002);OutputGlError("glPolygonOffsetEXT(-0.1, -0.002);") ;
  } else 
    {
      polygonOffsetVersion = MISSING;
      TRACE("\nAP210Viewer: Missing polygon offset.\n");
      TRACE("               Expect shadow depth aliasing artifacts.\n\n");
    }
#endif
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerView message handlers


/////////////////////////////////////////////////////////////////////////////
// OpenGL Code
//

void CAP210ViewerView::DrawScene() {
   // Enable blending for transpancy
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   // Enable depth calculations
   glEnable(GL_DEPTH_TEST);  		OutputGlError("glEnable (GL_DEPTH_TEST);") ;

   // Clear the color and depth buffers.
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f) ;
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Enable writing of frame buffer color components
   glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

   // Set the material color to follow the current color
   glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);  // The default.
   glEnable(GL_COLOR_MATERIAL) ;

   // Change to model view matrix stack.
   glMatrixMode(GL_MODELVIEW); OutputGlError("MatrixMode");
	
   // get to a known translation state.
   glLoadIdentity();

   // Translate the scene
   TranslateScene();

   // clear the color and depth bit buffers.
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); OutputGlError("glClear");

   // render the scene
   RenderScene();
   //
   // Flush the drawing pipeline.
   glFlush();	
   }
//
// PrepareScene()
//
// Prepare display lists for PWB, top and bottom components
//
void CAP210ViewerView::PrepareScene() {					   
   TRACE0("CAP210ViewerView::PrepareScene()\r\n");

   //
   // Attach the window dc to OpenGL.
   //
   CClientDC dc(this) ;
   BOOL bResult = wglMakeCurrent(dc.m_hDC, m_hrc);
   if (!bResult) {
      TRACE("wglMakeCurrent Failed in CAP210ViewerView::PrepareScene %x\r\n", GetLastError() ) ;
      }
   // Get PWB data
   CAP210ViewerDoc *doc =  GetDocument();

   TRACE("About to init display mode\r\n");
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);OutputGlError("glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);") ;

    // Setup Light Model
//    LightModel();

	// Setup select buffer
	TRACE("About to create Select Buffer\r\n");
	glSelectBuffer(MAXSELECT, selectBuf);OutputGlError("glSelectBuffer(MAXSELECT, selectBuf);") ;

// this shouldn't be here! MTK 3/19/2001

   // Scale Display (Really just centers the display)
   ScaleDisplay(); // A Test

   // Prepare PWB display list
   doc->PWB->Draw(); // Draw Green

   // Setup for non plated thru holes 
   AP210ObjectListItor NPTHitor(&(doc->NonPlatedThruHoles));

   // Prepare the non plated thru hole display lists
   NonPlatedThruHole *npth;
   NPTHitor.Reset();
   while((npth = (NonPlatedThruHole *)NPTHitor.NextDirectInstanceOf(NonPlatedThruHole::TypeID())) != NULL) {
      npth->Draw();
      }

   // Setup for components 
   AP210ObjectListItor Pitor(&(doc->Packages));

   // Prepare the package display lists
   Package *p;
   Pitor.Reset();
   while((p = (Package *)Pitor.NextDirectInstanceOf(Package::TypeID())) != NULL) {
      p->Draw();
      }

   // Setup for mechanical components 
   AP210ObjectListItor CDitor(&(doc->ComponentDefinitions));
   ComponentDefinition *cd;

   // Prepare the mechanical components display list
   CDitor.Reset();
   while((cd = (ComponentDefinition *)CDitor.NextDirectInstanceOf(ComponentDefinition::TypeID())) != NULL) {
      cd->Draw();
      }

   // Setup for mounting restriction areas 
   AP210ObjectListItor MRAitor(&(doc->MountingRestrictionAreas));
   MountingRestrictionArea *mra;

   // Prepare the  mounting restriction areas display list
   MRAitor.Reset();
   while((mra = (MountingRestrictionArea *)MRAitor.NextDirectInstanceOf(MountingRestrictionArea::TypeID())) != NULL) {
      mra->Draw();
      }

   wglMakeCurrent(NULL, NULL);
   }
//
//	OutputGlError
//
void CAP210ViewerView::OutputGlError(char* label)  {
	GLenum errorno = glGetError() ;
	if (errorno != GL_NO_ERROR) {
		TRACE("CAP210ViewerView: %s had error: #(%d) %s\r\n", label, errorno, gluErrorString(errorno)) ;
#if 0
		while(errorno != GL_NO_ERROR) {
			errorno = glGetError();
		TRACE("   %s had error: #(%d) %s\r\n", label, errorno, gluErrorString(errorno)) ;
		}
#endif
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//
// OpenGLpalette
//
unsigned char CAP210ViewerView::m_threeto8[8] = {
    0, 0111>>1, 0222>>1, 0333>>1, 0444>>1, 0555>>1, 0666>>1, 0377
};
unsigned char CAP210ViewerView::m_twoto8[4] = {
   0, 0x55, 0xaa, 0xff
};
unsigned char CAP210ViewerView::m_oneto8[2] = {
    0, 255
};

int CAP210ViewerView::m_defaultOverride[13] = {
    0, 3, 24, 27, 64, 67, 88, 173, 181, 236, 247, 164, 91
};

PALETTEENTRY CAP210ViewerView::m_defaultPalEntry[20] = {
    { 0,   0,   0,    0 }, //0
    { 0x80,0,   0,    0 }, 
    { 0,   0x80,0,    0 }, 
    { 0x80,0x80,0,    0 }, 
    { 0,   0,   0x80, 0 },
    { 0x80,0,   0x80, 0 },
    { 0,   0x80,0x80, 0 },
    { 0xC0,0xC0,0xC0, 0 }, //7

    { 192, 220, 192,  0 }, //8
    { 166, 202, 240,  0 },
    { 255, 251, 240,  0 },
    { 160, 160, 164,  0 }, //11

    { 0x80,0x80,0x80, 0 }, //12
    { 0xFF,0,   0,    0 },
    { 0,   0xFF,0,    0 },
    { 0xFF,0xFF,0,    0 },
    { 0,   0,   0xFF, 0 },
    { 0xFF,0,   0xFF, 0 },
    { 0,   0xFF,0xFF, 0 },
    { 0xFF,0xFF,0xFF, 0 }  //19
  };

//
// ComponentFromIndex
//
unsigned char CAP210ViewerView::ComponentFromIndex(int i, UINT nbits, UINT shift)
{
    unsigned char val;

    val = (unsigned char) (i >> shift);
    switch (nbits) {

    case 1:
        val &= 0x1;
        return m_oneto8[val];

    case 2:
        val &= 0x3;
        return m_twoto8[val];

    case 3:
        val &= 0x7;
        return m_threeto8[val];

    default:
        return 0;
    }
}

//
// CreateRGBPalette
//
BOOL CAP210ViewerView::CreateRGBPalette(HDC hDC)
{
	//
	// Check to see if we need a palette
	//
 	TRACE0("Checking palette\r\n") ;
    PIXELFORMATDESCRIPTOR pfd;
    int n = GetPixelFormat(hDC);
    DescribePixelFormat(hDC, n, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	if (!(pfd.dwFlags & PFD_NEED_PALETTE)) return FALSE ;

	TRACE0("Creating palette\r\n") ;
    // allocate a log pal and fill it with the color table info
    LOGPALETTE* pPal = (LOGPALETTE*) malloc(sizeof(LOGPALETTE) 
                     + 256 * sizeof(PALETTEENTRY));
    if (!pPal) 
    {
        TRACE("Out of memory for logpal");
        return FALSE;
    }
    pPal->palVersion = 0x300; // Windows 3.0
    pPal->palNumEntries = 256; // table size

	//
	// Create RGB Palette
	//
	ASSERT( pfd.cColorBits == 8) ;
     n = 1 << pfd.cColorBits;
    for (int i=0; i<n; i++)
    {
        pPal->palPalEntry[i].peRed =
                ComponentFromIndex(i, pfd.cRedBits, pfd.cRedShift);
        pPal->palPalEntry[i].peGreen =
                ComponentFromIndex(i, pfd.cGreenBits, pfd.cGreenShift);
        pPal->palPalEntry[i].peBlue =
                ComponentFromIndex(i, pfd.cBlueBits, pfd.cBlueShift);
        pPal->palPalEntry[i].peFlags = 0;
    }

	//
	// Fix up color table with system colors.
	//
    if ((pfd.cColorBits == 8)                           &&
        (pfd.cRedBits   == 3) && (pfd.cRedShift   == 0) &&
        (pfd.cGreenBits == 3) && (pfd.cGreenShift == 3) &&
        (pfd.cBlueBits  == 2) && (pfd.cBlueShift  == 6)
       )
    {
	    for (int j = 1 ; j <= 12 ; j++)
	          pPal->palPalEntry[m_defaultOverride[j]] = m_defaultPalEntry[j];
	}

    // Delete any existing GDI palette
	if (m_pPal) delete m_pPal ;
	m_pPal = new CPalette ;

    BOOL bResult = m_pPal->CreatePalette(pPal);
    free (pPal);

    return bResult;
}

//
// OnSize
//
void CAP210ViewerView::OnSize(UINT nType, int cx, int cy) {

	TRACE0("CAP210ViewerView::OnSize\r\n");
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if ( (cx <= 0) || (cy <= 0) )
      return;
	
    CClientDC dc(this);
	//
	// Make the rendering context m_hrc current
	//
   BOOL bResult = wglMakeCurrent(dc.m_hDC, m_hrc);
	if (!bResult) {
		TRACE("wglMakeCurrent Failed %x\r\n", GetLastError() );
		return;
   	}
   // Set the OpenGL perspective
   glMatrixMode(GL_PROJECTION); OutputGlError("OnSize MatrixMode");
   glLoadIdentity();
   Perspective();
	//
	// No rendering context will be current.
	//
   wglMakeCurrent(NULL, NULL);	
   }
//
// OnDestroy
//
void CAP210ViewerView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	wglMakeCurrent(NULL,NULL); 
	if (m_hrc) 
	{
		wglDeleteContext(m_hrc) ;
		m_hrc = NULL ;
	}		
}
//
//	OnEraseBkgnd
//
BOOL CAP210ViewerView::OnEraseBkgnd(CDC* pDC) {
   // TODO: Add your message handler code here and/or call default
	
   return TRUE ;
   //return CView::OnEraseBkgnd(pDC);
   }

void CAP210ViewerView::DrawRuler(GLdouble x, GLdouble y) {
   double tick = 0.1;
   double length = 1.0;
   // white
   glColor3f(1.0, 1.0, 1.0);

   // line
   glBegin(GL_LINES);
   glVertex2f(x, y);
   glVertex2f(length+x, y);
   glEnd();

   // start
   glBegin(GL_LINES);
   glVertex2f(x, -tick+y);
   glVertex2f(x,  tick+y);
   glEnd();

   glBegin(GL_LINES);
   glVertex2f(0.125*length + x, -0.25*tick+y);
   glVertex2f(0.125*length + x,  0.25*tick+y);
   glEnd();


   glBegin(GL_LINES);
   glVertex2f(0.25*length + x, -0.5*tick+y);
   glVertex2f(0.25*length + x,  0.5*tick+y);
   glEnd();

   glBegin(GL_LINES);
   glVertex2f(0.375*length + x, -0.25*tick+y);
   glVertex2f(0.375*length + x,  0.25*tick+y);
   glEnd();

   // middle
   glBegin(GL_LINES);
   glVertex2f(0.5*length + x, -0.75*tick+y);
   glVertex2f(0.5*length + x,  0.75*tick+y);
   glEnd();

   glBegin(GL_LINES);
   glVertex2f(0.625*length + x, -0.25*tick+y);
   glVertex2f(0.625*length + x,  0.25*tick+y);
   glEnd();


   glBegin(GL_LINES);
   glVertex2f(0.75*length + x, -0.5*tick+y);
   glVertex2f(0.75*length + x,  0.5*tick+y);
   glEnd();

   glBegin(GL_LINES);
   glVertex2f(0.875*length + x, -0.25*tick+y);
   glVertex2f(0.875*length + x,  0.25*tick+y);
   glEnd();

   // end
   glBegin(GL_LINES);
   glVertex2f(1.0 + x, -tick+y);
   glVertex2f(1.0 + x,  tick+y);
   glEnd();
   }

void CAP210ViewerView::DrawOrigin(GLdouble x, GLdouble y) {
   glBegin(GL_LINES);
   glVertex2f (-1.0+x, y);
   glVertex2f ( 1.0+x, y);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f (x, -1.0+y);
   glVertex2f (x,  1.0+y);
   glEnd();
   }

// This could be accomplished with a transformation.
// no scaling is being done, the origin is being moved
// to the center of the board. The min and max should
// be calculated ExtractGeometry.
void CAP210ViewerView::ScaleDisplay() {
   double Height;
   double Width;

   CAP210ViewerDoc* pDoc = GetDocument();
   AP210Point *point;
   AP210ObjectListItor itor(&(pDoc->PWB->Points));

   double MinX = HUGE_VAL;
   double MaxX = -HUGE_VAL;
   double MinY = HUGE_VAL;
   double MaxY = -HUGE_VAL;

   itor.Reset();
   while((point = (AP210Point *)itor.NextInstanceOf(AP210Point::TypeID())) != NULL) {

      if (point->X < MinX) {
         MinX = point->X;
         }
      if (point->X > MaxX) {
         MaxX = point->X;
         }
      if (point->Y < MinY) {
         MinY = point->Y;
         }
      if (point->Y > MaxY) {
         MaxY = point->Y;
         }
      }
   Width  = MaxX - MinX;
   Height = MaxY - MinY;
 
   // here is the key to centering the board
   DeltaX = (MaxX + MinX)/2.0;
   DeltaY = (MaxY + MinY)/2.0;
#ifdef VERBOSE 
   TRACE("MaxX: %f, MinX: %f\n", MaxX, MinX);
   TRACE("MaxX + MinX: %f\r\n", MaxX + MinX);
   TRACE("MaxY: %f, MinY: %f\n", MaxY, MinY);
   TRACE("MaxY + MinY: %f\r\n", MaxY + MinY);
   TRACE("DeltaX: %f, DeltaY: %f\n", DeltaX, DeltaY);
#endif
   // Center the eye on the board.
   // This really just centers the view it 
   // doesn't change the point of rotation.
   eyeX = DeltaX;
   eyeY = DeltaY;

   centerX = eyeX;
   centerY = eyeY;
   }
void CAP210ViewerView::OnMouseMove(UINT nFlags, CPoint point) {
	// TODO: Add your message handler code here and/or call default

   if (focus == TRUE) {
      if (nFlags & MK_LBUTTON) {
#ifdef TRACKBALL
int W = 300, H = 300;
       trackball(lastquat,
         (2.0 * startx - W) / W,
         (H - 2.0 * starty) / H,
         (2.0 * point.x - W) / W,
         (H - 2.0 * point.y) / H
         );
         newModel = 1;
#else
#ifdef VERBOSE
TRACE("Move Point: (%ld, %ld)\r\n", point.x, point.y);
TRACE("     Start: (%ld, %ld)\r\n", startx, starty);
TRACE("    Angles: (%f, %f)\r\n", angle, angle2);
#endif
         angle = angle + (point.x - startx);
         angle2 = angle2 + (point.y - starty);

#ifdef VERBOSE
TRACE("    Angles: (%f, %f)\r\n", angle, angle2);
#endif
#endif
         // reset start
         startx = point.x;
         starty = point.y;

         Invalidate();  // force a repaint
         }
      }
	CView::OnMouseMove(nFlags, point);
   }
void CAP210ViewerView::OnLButtonDown(UINT nFlags, CPoint point) {
	// TODO: Add your message handler code here and/or call default
   if (focus == TRUE) {
#ifdef VERBOSE
TRACE("Down Point: (%ld, %ld)\r\n", point.x, point.y);
TRACE("     Start: (%ld, %ld)\r\n", startx, starty);
TRACE("    Angles: (%f, %f)\r\n", angle, angle2);
#endif
      startx = point.x;
      starty = point.y;
/* Implement this from mouse
mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
      starty = y;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
  if (button == GLUT_MIDDLE_BUTTON) {
    if (state == GLUT_DOWN) {
      lightMoving = 1;
      lightStartX = x;
      lightStartY = y;
    }
    if (state == GLUT_UP) {
      lightMoving = 0;
    }
  }
}
*/	
      }
	CView::OnLButtonDown(nFlags, point);
}

BOOL CAP210ViewerView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) {
	// TODO: Add your message handler code here and/or call default
static short accum = 0;  // accumulate zDeltas, should this
                         // be set to zero in OnChar() also?
   if (focus == TRUE) {
#ifdef VERBOSE
TRACE("Wheel Point: (%ld, %ld)\r\n", pt.x, pt.y);
TRACE("     zDelta: %ld\r\n", zDelta);
#endif	
      accum += zDelta;
      if (accum >= 120) {
         accum = 0;
         eyeZ++;        // Move away from model
         Invalidate();  // force a repaint
         }
      else if (accum <= -120) {
         accum = 0;
         eyeZ--;        // Move toward model
         Invalidate();  // force a repaint
         }
      }
   return CView::OnMouseWheel(nFlags, zDelta, pt);
   }

void CAP210ViewerView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	// TODO: Add your message handler code here and/or call default
   if (focus == TRUE) {
#ifdef VERBOSE
TRACE("OnChar nChar: %ld - '%c'\r\n", nChar, nChar);
TRACE("     nRepCnt: %ld\r\n", nRepCnt);   
#endif		
      switch(nChar) {
         case '+':
            eyeZ-=0.1;
//            eyeZ--;
#ifdef VERBOSE
TRACE("eyeZ: %f\r\n", eyeZ);
#endif		
            Invalidate();
            break;
         case '-':
//            eyeZ++;
            eyeZ+=0.1;
#ifdef VERBOSE
TRACE("eyeZ: %f\r\n", eyeZ);
#endif		
            Invalidate();
            break;
// eyeX and eyeY need to be incremented in smaller amounts.
         case '8':
            eyeY-=0.1;
            centerY-=0.1;
            Invalidate();
            break;
         case '2':
            eyeY+=0.1;
            centerY+=0.1;
            Invalidate();
            break;
         case '6':
            eyeX-=0.1;
            centerX-=0.1;
            Invalidate();
            break;
         case '4':
            eyeX+=0.1;
            centerX+=0.1;
            Invalidate();
            break;
         }
      }   
 	CView::OnChar(nChar, nRepCnt, nFlags);
   }
#ifdef TRACKBALL
void CAP210ViewerView::recalcModelView() {
   GLfloat m[4][4];

// This is really weird why a pop than a push?
   glPopMatrix();
   glPushMatrix();
   add_quats(lastquat, curquat, curquat);
   build_rotmatrix(m, curquat);
   glMultMatrixf(&m[0][0]);
#if 0
   if (scalefactor == 1.0) {
      glDisable(GL_NORMALIZE);
      }
   else {
      glEnable(GL_NORMALIZE);
      }
   glScalef(scalefactor, scalefactor, scalefactor);
   glTranslatef(-8, -8, -bodyWidth / 2);
#endif
   newModel = 0;
   }
#endif
void CAP210ViewerView::OnSetFocus(CWnd* pOldWnd) {
   CView::OnSetFocus(pOldWnd);
	
   // TODO: Add your message handler code here
   focus = TRUE;	
   }

void CAP210ViewerView::OnKillFocus(CWnd* pNewWnd) {
   CView::OnKillFocus(pNewWnd);
	
   // TODO: Add your message handler code here
   focus = FALSE;	
   }

void CAP210ViewerView::OnLButtonDblClk(UINT nFlags, CPoint point) {
   // TODO: Add your message handler code here and/or call default
   if (focus == TRUE) {
#ifdef VERBOSE
TRACE("Left Double Click point: (%ld, %ld)\r\n", point.x, point.y);
TRACE("                  flags: 0x%08x\r\n", nFlags);
#endif	
      int hitresult;
      hitresult = OnSelect(point.x, point.y);
#ifdef VERBOSE
TRACE("Hit Result: %d\r\n", hitresult);
#endif
      ProcessHits(hitresult, selectBuf);
      }	
   CView::OnLButtonDblClk(nFlags, point);
   }

void CAP210ViewerView::OnRButtonDblClk(UINT nFlags, CPoint point) {
	// TODO: Add your message handler code here and/or call default

   // Select the items, really should select only one in this case.
   if (focus == TRUE) {
      int hitresult;
      hitresult = OnSelect(point.x, point.y);

      ProcessHits(hitresult, selectBuf);

      CAP210ViewerDoc* pDoc = GetDocument();

      if (pDoc->AP210Model != sdaiNULL) { // filters out IDF
         
         if (pDoc->numComponentsSelected() == 1) {
            AP210ObjectList selected;

            if (pDoc->PWB->isSelected()) {
               // create the dialog box
               CInterconnectModulePropertiesSheet interconnectmodulepropDlg("Interconnect Module Properties", this);

               // set the dialog boxes values
               interconnectmodulepropDlg.setValues(pDoc->AP210Model, pDoc->PWB);
               interconnectmodulepropDlg.setReadOnly(pDoc->ReadOnly);

               // display the dialog box
               interconnectmodulepropDlg.DoModal();
               }
            else if (pDoc->getSelectedPackagedComponents(&selected) == 1) {
               PackagedComponent *pc = (PackagedComponent *)selected.First();
               // create the dialog box
               CComponentPropertiesSheet comppropDlg("Packaged Component Properties", this);

               // set the dialog boxes values
               comppropDlg.setValues(pDoc->AP210Model, pc);
               comppropDlg.setReadOnly(pDoc->ReadOnly);

               // display the dialog box
               comppropDlg.DoModal();
               }
            else if (pDoc->getSelectedComponentDefinitions(&selected) == 1) {
               ComponentDefinition *cd = (ComponentDefinition *)selected.First();
               // create the dialog box
               CComponentDefinitionSheet comppropDlg("Mechanical Part Properties", this);

               // set the dialog boxes values
               comppropDlg.setValues(pDoc->AP210Model, cd);
               comppropDlg.setReadOnly(pDoc->ReadOnly);

               // display the dialog box
               comppropDlg.DoModal();
               }
            }
         else {
            AP210ObjectList selected;
            if (pDoc->getSelectedNonPlatedThruHoles(&selected) == 1) {

               NonPlatedThruHole *npth = (NonPlatedThruHole *)selected.First();

               // create the dialog box
               CNonPlatedThruHoleSheet npthpropDlg("Non-Plated Thru Hole Properties", this);

               // set the dialog boxes values
               npthpropDlg.setValues(pDoc->AP210Model, npth);
               npthpropDlg.setReadOnly(pDoc->ReadOnly);

               // display the dialog box
               npthpropDlg.DoModal();
               }
            else { 
               AP210ObjectList selected;
               if (pDoc->getSelectedMountingRestrictionAreas(&selected) == 1) {

                  MountingRestrictionArea *mra = (MountingRestrictionArea *)selected.First();

                  // create the dialog box
                  CComponentPlacementRestrictionAreaSheet mrapropDlg("Component Placement Restriction Area Properties", this);

                  // set the dialog boxes values
                  mrapropDlg.setValues(pDoc, mra);
                  mrapropDlg.setReadOnly(pDoc->ReadOnly);

                  // display the dialog box
                  mrapropDlg.DoModal();
                  }
               }
            }
         } 
      }	
	CView::OnRButtonDblClk(nFlags, point);
   }
/*
 * OnSelect()
 *
 * Select the components at x y.
 */
int CAP210ViewerView::OnSelect(int x, int y) {
#ifdef VERBOSE
  GLdouble modelMatrix[16];
  GLdouble projMatrix[16];
  GLdouble objx, objy, objz;
#endif
  GLint viewport[4];
  GLint hits;
  GLint PickBoxSize = 1;
   //
   // Attach the window dc to OpenGL.
   //
   CClientDC dc(this) ;
   BOOL bResult = wglMakeCurrent(dc.m_hDC, m_hrc);
   if (!bResult) {
      TRACE("wglMakeCurrent Failed in CAP210ViewerView::OnSelect %x\r\n", GetLastError());
      }
   // Get the viewport
   glGetIntegerv(GL_VIEWPORT, viewport);

   glRenderMode(GL_SELECT); OutputGlError("A glRenderMode(GL_SELECT);");
   glInitNames();
   glPushName(~0);

   // Change to model view matrix stack.
   glMatrixMode(GL_MODELVIEW); 	OutputGlError("MatrixMode");

   // save the current model view matrix.
   glPushMatrix();
	
   // get to a known translation state.
   glLoadIdentity();

   // Translate the scene
   TranslateScene();

#ifdef VERBOSE
   // Translate x and y from window to object coordinates.
   // This does work, but nothing is getting picked.
   glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
   glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);
   gluUnProject(x, y, 0, modelMatrix, projMatrix, viewport, &objx, &objy, &objz);

TRACE("x: %d, y: %d, objx: %f, objy: %f\n", x, y, objx, objy);
#endif

   // select related modification made to projection matrix
   glMatrixMode(GL_PROJECTION); OutputGlError("MatrixMode");

   // save the current projection matrix.
   glPushMatrix();

   // clear the projection matrix
   glLoadIdentity();

   // setup pick matrix, VERY important to do this before the perspective is set.
   gluPickMatrix(x, viewport[3] - y, PickBoxSize, PickBoxSize, viewport);

   // Set the OpenGL perspective
   Perspective();

   // clear the color and depth bit buffers.
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // render the scene, in the model view due to translations in 
   // PackagedComponents Render functions.
   glMatrixMode(GL_MODELVIEW); 	OutputGlError("MatrixMode modelview restore");

   // just a single render pass required for selection
   RenderScenePass();

   hits = glRenderMode(GL_SELECT); 	OutputGlError("B glRenderMode(GL_SELECT);");
 
  // Restore Render Mode.
   glRenderMode(GL_RENDER); OutputGlError("glRenderMode(GL_RENDER);");
#ifdef VERBOSE
TRACE("Hits %d\r\n", hits);
#endif
   // restore the projection matrix.
   glMatrixMode(GL_PROJECTION); OutputGlError("MatrixMode");
   glPopMatrix(); 	OutputGlError("glPopMatrix");

   // restore the modelview matrix
   glMatrixMode(GL_MODELVIEW); 	OutputGlError("MatrixMode modelview restore");
   glPopMatrix();

   // Release the windows dc.
   wglMakeCurrent(NULL,NULL); 

   if (hits <= 0) {
      return -1;
      }
   return hits; // selectBuf[(hits - 1) * 4 + 3];
   }
/*
 * CAP210ViewerView::ProcessHits()
 *
 * Process selection array and calls isSelected() for 
 * the topmost component.
 *
 * It sure would be nice to be able to cycle through
 * the components.
 */
void CAP210ViewerView::ProcessHits(GLint hits, GLuint buffer[]) {
   int i, j;
   GLuint names;
   GLuint maxname;
   GLuint maxnames;
   float Z;
   float minZ = HUGE_VAL;
   GLuint *ptr;
   bool selection = false;
   CAP210ViewerDoc* pDoc = GetDocument();
   
   // Unselect the PWB and all the components
   pDoc->UnSelectAll();

#ifdef FILEVERBOSE
    FILE *myfp = fopen("c:\\keenan\\sel.txt", "w");
#endif

#ifdef VERBOSE
   TRACE("hits = %d\n", hits);
#endif
   ptr = (GLuint *) buffer;
   for(i = 0; i < hits; i++) {	/*  for each hit  */
      names = *ptr;
#ifdef VERBOSE
      TRACE(" number of names for hit = %d\n", names);
#endif
      ptr++;
      Z = (float)*ptr/0x7fffffff;
#ifdef VERBOSE
      TRACE(" Z is %g;\n", Z);
#endif
      if (minZ > Z) {
          minZ = Z;
          maxnames = names;
#ifdef VERBOSE
          TRACE("Set minZ: %g\n", minZ);
          TRACE("maxnames: 0x%08x\n", maxnames);
#endif
          }
      ptr++;
#ifdef VERBOSE
      TRACE(" z2 is %g;", (float) *ptr/0x7fffffff);
#endif
      ptr++;
      for(j = 0; j < (int)names; j++) {	/*  for each name */
#ifdef VERBOSE
         TRACE ("   the name is %d\n", *ptr);
         TRACE("checking minZ: %g, Z %g\n", minZ, Z);
#endif
         if (minZ == Z) {
            maxname = *ptr;
#ifdef VERBOSE
            TRACE("Set maxname: %d\n", maxname); 
#endif
            }
         ptr++;
         }
      }
#ifdef VERBOSE
   TRACE("Result: MAX number of names for hit = %d\n", maxnames);
   TRACE("  maxname: %d\n", maxname);
   TRACE("  minZ: %g\n", minZ);
   TRACE("\nTraverse:\n");
#endif
   if (!pDoc->PWB->Select(maxname)) {
      // Setup for components 
      AP210ObjectListItor CDitor(&(pDoc->ComponentDefinitions));
      ComponentDefinition *cd;
      // PWB not selected
      // was a component selected?
      CDitor.Reset();
      while((cd = (ComponentDefinition *)CDitor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {
#ifdef VERBOSE
         TRACE("looking at component\n");
#endif
         // since everything was unselected and something can
         // only be selected once, we can break here if the
         // item is selected.
         if (!cd->isSelected()) {
            if (cd->Select(maxname)) {
               selection = true;
#ifdef VERBOSE
               TRACE("component selected\n");
#endif
               break;
               }
            }
         }
      // Check MountingRestrictionAreas for selection
      if (!selection) {
         AP210ObjectListItor MRAitor(&(pDoc->MountingRestrictionAreas));
         MountingRestrictionArea *mra;
         MRAitor.Reset();
         while((mra = (MountingRestrictionArea *)MRAitor.NextDirectInstanceOf(MountingRestrictionArea::TypeID())) != NULL) {
            if (!mra->isSelected()) {
               if (mra->Select(maxname)) {
                  selection = true;
                  break;
                  }
               }
            }
         }       
      // Check NonPlatedThruHoles for selection
      if (!selection) {
         AP210ObjectListItor NPTHitor(&(pDoc->NonPlatedThruHoles));
         NonPlatedThruHole *npth;
         NPTHitor.Reset();
         while((npth = (NonPlatedThruHole *)NPTHitor.NextDirectInstanceOf(NonPlatedThruHole::TypeID())) != NULL) {
            if (!npth->isSelected()) {
               if (npth->Select(maxname)) {
                  selection = true;
                  break;
                  }
               }
            }
         }       
      }
#ifdef VERBOSE
   else {
      TRACE("PWB selected\n");
      }
#endif
   // Have the document handle the selected items.
   pDoc->OnSelection();

   // Update all the views to highlight what was selected.
   pDoc->UpdateAllViews(NULL);
#ifdef FILEVERBOSE
   fclose(myfp);
#endif
   }

void CAP210ViewerView::RenderScene() {
   glEnable(GL_ALPHA_TEST);

   // Display non transparent items
   glAlphaFunc(GL_EQUAL, 1.0);
   RenderScenePass();

   // Display transparent items
   glAlphaFunc(GL_NOTEQUAL, 1.0);
   RenderScenePass();

   glDisable(GL_ALPHA_TEST);
   }
void CAP210ViewerView::RenderScenePass() {
	CAP210ViewerDoc* pDoc = GetDocument();
   // Setup for non plated thru holes
   AP210ObjectListItor NPTHitor(&(pDoc->NonPlatedThruHoles));
   NonPlatedThruHole *npth;

   // Setup for components 
   AP210ObjectListItor CDitor(&(pDoc->ComponentDefinitions));
   ComponentDefinition *cd;

   // Setup for Mounting Restriction Areas.
   AP210ObjectListItor MRAitor(&(pDoc->MountingRestrictionAreas));
   MountingRestrictionArea *mra;
   
   double base = pDoc->PWB->getConstructionThickness();
//#define SETMATERIAL
#ifdef SETMATERIAL
	// Set up some colors
   static GLfloat red[] = { 1.0, 0.0, 0.0, 0.0 };
   static GLfloat blue[] = { 0.0, 0.0, 1.0, 0.0 };
   static GLfloat green[] = { 0.0, 1.0, 0.0, 0.0 };
   // display the PCB green
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, green);
#endif
   pDoc->PWB->Render(0.0, 1.0, 0.0); // Render Green

   // Non Plated Thru holes.
#ifdef SETMATERIAL
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
#endif
   // Render the non plated thru holes display list
   CDitor.Reset();
   while((npth = (NonPlatedThruHole *)NPTHitor.NextInstanceOf(NonPlatedThruHole::TypeID())) != NULL) {

      npth->setSeatingPlane(base);
      npth->Render(0.0, 0.0, 0.0); // Draw Black
      }
   // Top Components
#ifdef SETMATERIAL
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
#endif
   // Render the top components display list
   CDitor.Reset();
   while((cd = (ComponentDefinition *)CDitor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {

      if (cd->Side == Top) {
         cd->setSeatingPlane(base);
         cd->Render(1.0, 0.0, 0.0); // Draw Red
         }
      }
   // Bottom components
#ifdef SETMATERIAL
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blue);
#endif
   // Render the bottom components display list
   CDitor.Reset();
   while((cd = (ComponentDefinition *)CDitor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {

      if (cd->Side == Bottom) {
         cd->setSeatingPlane(0.0);
         cd->Render(0.0, 0.0, 1.0); // Render Blue
         }
      }
   // Mounting Restriction Areas
   // Render the restriction areas display list
   // All will be the same color
   MRAitor.Reset();
   while((mra = (MountingRestrictionArea *)MRAitor.NextInstanceOf(MountingRestrictionArea::TypeID())) != NULL) {
      if (mra->Side == Top) {
         mra->setSeatingPlane(base);
         }
      else if (mra->Side == Bottom) {        
         mra->setSeatingPlane(0.0);
         }
      mra->Render(1.0, 1.0, 0.0); // Draw Yellow
      }
   
   }
void CAP210ViewerView::TranslateScene() {
   // Translate and rotate the axis.
   // Need to find a better way to do this look at DisplayLines.c
   // Set distance from PWA and always look at.
#if 1
#if 1
#if 0
   gluLookAt(eyeX, eyeY, eyeZ, eyeX, eyeY, 0.0, upX, upY, upZ);
#else
   // center the board on the orign
//   glTranslated(-DeltaX, -DeltaY, -eyeZ);
   glTranslated(0.0,0.0, -eyeZ);
   // rotate the board
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   // put the board back
//   glTranslated(DeltaX, DeltaY, eyeZ);
   glTranslated(0.0,0.0, eyeZ);
   // look at the board
   gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0.0, 1.0, 0.0);
#ifdef VERBOSE
TRACE("eye: (%f, %f, %f)\r\n", eyeX, eyeY, eyeZ);
TRACE("center: (%f, %f, %f)\r\n", centerX, centerY, centerZ);
TRACE("up: (%f, %f, %f)\r\n", upX, upY, upZ);
TRACE("angle2: %f, angle: %f\r\n", angle2, angle);
TRACE("DeltaX: %f, DeltaY: %f\r\n", DeltaX, DeltaY);
#endif
#endif
#else
   // 45 degree rotation about Z axis.
//   gluLookAt(eyeX, eyeY, eyeZ, eyeX, eyeY, 0.0, 2.0, 2.0, -1.0);
//   gluLookAt(eyeX, eyeY, eyeZ, eyeX, eyeY, 0.0, angle2, angle, 0.0);
//   gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0.0, 1.0, 0.0);
  
   // this is ackward looking
   GLfloat lookat[3], perp[3], up[3];
   GLfloat az = angle;
   GLfloat el = angle2;

   lookat[0] = sin(TORAD(az))*cos(TORAD(el));
   lookat[1] = sin(TORAD(el));
   lookat[2] = -cos(TORAD(az))*cos(TORAD(el));
   normalize(lookat);
   perp[0] = lookat[2];
   perp[1] = 0;
   perp[2] = -lookat[0];
   normalize(perp);
   ncrossprod(lookat, perp, up);
   gluLookAt(eyeX, eyeY, eyeZ,
             eyeX+lookat[0], eyeY+lookat[1], eyeZ+lookat[2],
             up[0], up[1], up[2]);
#endif

   /* Perform scene rotations based on user mouse input. */
#else
#ifdef TRACKBALL
   if (newModel) { // isn't set every it is needed.
      recalcModelView();
      }
#else
   // this is currently a model transformation,
   //  it should be a viewing transformation.
   // probably should do this all with gluLookAt
#if 0
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
#endif
#endif  
#endif
   }

void CAP210ViewerView::Perspective() {
   CRect rect;
   int cx;
   int cy;
   //
   // Set up the mapping of 3D-space to screen space
   //
   GetClientRect(&rect);
   cx = rect.Width();
   cy = rect.Height();

   GLdouble gldAspect = (GLdouble) cx/ (GLdouble) cy;
   glMatrixMode(GL_PROJECTION); OutputGlError("OnSize MatrixMode");

   // No clipping desired in the Z axis.
   gluPerspective(glFovy, gldAspect, glNear, glFar);
   glViewport(0, 0, cx, cy);
   }

double CAP210ViewerView::calculateAngle(double size, double distance) {
   double radtheta, degtheta;

   radtheta = 2.0 * atan2(size/2.0, distance);
   degtheta = TODEG(radtheta);

   return degtheta;
   }

double CAP210ViewerView::calculateDistance(double size, double degtheta) {

   double radtheta, distance;

   radtheta = TORAD(degtheta);
   distance = size/(2.0*tan(radtheta/2.0));

   // create a boarder
   distance = distance;

   if (distance < 2.0) {
      distance = 2.0;
      }
   return distance;
   }

void CAP210ViewerView::set_eyeZ() {
   CRect rect;
   int cx;
   int cy;
   double dx, dy;
   //
   // Calculate the distance to the board inorder 
   // to see all of it.
   //
   // get the size of the window
   GetClientRect(&rect);
   cx = rect.Width();
   cy = rect.Height();

   // calculate ideal distance
   dy = calculateDistance((double)cx, glFovy);
   // calculate field of view in x
   double AngleX = calculateAngle(cy, dy);

   // the fudge factors used here might be caused by
   //   1. boards to the drawing rectangle.
   //   2. cx and cy being in not square pixels.
   dx = calculateDistance(DeltaX, AngleX)*1.5;
   dy = calculateDistance(DeltaY, glFovy)*1.1;

   // use the greater distance
   if (dx > dy) {
      eyeZ = dx;
      }
   else {
      eyeZ = dy;
      }
   }

void CAP210ViewerView::OnComponentRestrictionArea() {
   // TODO: Add your command handler code here

   // create the dialog box
   CComponentPlacementRestriction craDlg;


   // display the dialog box
   craDlg.setValues(GetDocument());
   craDlg.DoModal();
   }

void CAP210ViewerView::orientPrimarySurface() {
   // The code below needs to be parameterized
   // for both the primary which is below and
   // the secondary surfaces.
   
   // Centering Initialization
   DeltaX = 0.0;
   DeltaY = 0.0;

   // Perspective Initialization
   glFovy = 30.0;
   glNear = 1.0;
   glFar = 100.0;
//---------
   // Model Orientation Initialization
   angle = 0;
   angle2 = 0;

   // Eye Orientation Initialization
   eyeX = 0.0;
   eyeY = 0.0;
   eyeZ = 3.0;

   // Camera Position
   centerX = eyeX;
   centerY = eyeY;
   centerZ = 0.0;

   // Camera Orientation;
   upX = 0.0;
   upY = 1.0;
   upZ = 0.0;
   }

void CAP210ViewerView::orientSecondarySurface() {
   // The code below needs to be parameterized
   // for both the primary which is below and
   // the secondary surfaces.
   
   // Centering Initialization
   DeltaX = 0.0;
   DeltaY = 0.0;

   // Perspective Initialization
   glFovy = 30.0;
   glNear = 1.0;
   glFar = 100.0;
//---------
   // Model Orientation Initialization
   angle = 180;
   angle2 = 0;

   // Eye Orientation Initialization
   eyeX = 0.0;
   eyeY = 0.0;
   eyeZ = 3.0;

   // Camera Position
   centerX = eyeX;
   centerY = eyeY;
   centerZ = 0.0;

   // Camera Orientation;
   upX = 0.0;
   upY = 1.0;
   upZ = 0.0;
  }

void CAP210ViewerView::OnPrimarySurface() {
	// TODO: Add your command handler code here
   orientPrimarySurface();	

   // Scale Display (Really just centers the display)
   ScaleDisplay();

   // backup so the entire model is displayed
   set_eyeZ();

   // force a repaint
   Invalidate();
   }

void CAP210ViewerView::OnSecondarySurface() {
	// TODO: Add your command handler code here
   orientSecondarySurface();	

   // Scale Display (Really just centers the display)
   ScaleDisplay();

   // backup so the entire model is displayed
   set_eyeZ();

   // force a repaint
   Invalidate();
   }
#ifdef DUMPMODELVIEW
void CAP210ViewerView::dumpModelView() {
   TRACE("Centering Initialization\r\n");
   TRACE("  DeltaX: %f\r\n", DeltaX);
   TRACE("  DeltaY: %f\r\n", DeltaY);

   TRACE("Perspective Initialization\r\n");
   TRACE("  glFovy: %f\r\n", glFovy);
   TRACE("  glNear: %f\r\n", glNear);
   TRACE("  glFar: %f\r\n", glFar);
//---------
   TRACE("Model Orientation Initialization\r\n");
   TRACE("  angle: %f\r\n", angle);
   TRACE("  angle2: %f\r\n", angle2);

   TRACE("Eye Orientation Initialization\r\n");
   TRACE("  eyeX: %f\r\n", eyeX);
   TRACE("  eyeY: %f\r\n", eyeY);
   TRACE("  eyeZ: %f\r\n", eyeZ);

   TRACE("Camera Position\r\n");
   TRACE("  centerX: %f\r\n", centerX);
   TRACE("  centerY: %f\r\n", centerY);
   TRACE("  centerZ: %f\r\n", centerZ);

   TRACE("Camera Orientation\r\n");
   TRACE("  upX: %f\r\n", upX);
   TRACE("  upY: %f\r\n", upY);
   TRACE("  upZ: %f\r\n", upZ);
   }
#endif