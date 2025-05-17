// AP210ViewerView.h : interface of the CAP210ViewerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AP210VIEWERVIEW_H__9BE7D70F_0912_11D3_9B0D_0080AD428934__INCLUDED_)
#define AFX_AP210VIEWERVIEW_H__9BE7D70F_0912_11D3_9B0D_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CAP210ViewerView : public CView
{
protected: // create from serialization only
	CAP210ViewerView();
	DECLARE_DYNCREATE(CAP210ViewerView)

// Attributes
public:
	CAP210ViewerDoc* GetDocument();

	HGLRC m_hrc;       //OpenGL Rendering Context for Display
   HGLRC p_hrc;       // OpenGL Rendering Context for Printing
                      // Is a different context required for printing?
	CPalette* m_pPal;  //Palette

// Operations
public:
	void PrepareScene() ; 	//OPENGL build display lists
	void DrawScene() ;		//OPENGL draws OpenGL scene
	void OutputGlError(char* label) ; //OPENGL function to display OpenGL errors using TRACE
	
	//
	// Multiple display list support
	//
	enum enum_OBJECTS {thePCB=1, theTopComponents=2, theBottomComponents=3} ;		
	
	//
	// Support for generating RGB color palette
	//
	BOOL CreateRGBPalette(HDC hDC)	;
	unsigned char ComponentFromIndex(int i, UINT nbits, UINT shift) ;
 	static unsigned char   m_oneto8[2];
   static unsigned char   m_twoto8[4];
   static unsigned char   m_threeto8[8];
   static int             m_defaultOverride[13];
   static PALETTEENTRY    m_defaultPalEntry[20];

// Operations
public:

// Overrides
 //   virtual void OnDestroy();
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAP210ViewerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
   virtual void OnInitialUpdate();
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL
//    virtual int OnCreate(LPCREATESTRUCT lpCreateStruct);  // setup OPENGL here 

// Implementation
public:
	void Perspective();
	int lightStartY;
	virtual ~CAP210ViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void ScaleDisplay(void);
	void DrawOrigin(GLdouble x, GLdouble y);
	void DrawRuler(GLdouble x, GLdouble y);

// Generated message map functions
protected:
	//{{AFX_MSG(CAP210ViewerView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnComponentRestrictionArea();
	afx_msg void OnPrimarySurface();
	afx_msg void OnSecondarySurface();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
#ifdef DUMPMODELVIEW
	void dumpModelView();
#endif
	void orientSecondarySurface();
	void orientPrimarySurface();
	double DeltaY;
	double DeltaX;
	double calculateDistance(double size, double degtheta);
	double calculateAngle(double size, double distance);
	void set_eyeZ();
	virtual void TranslateScene();
	virtual void RenderScene();
	virtual void RenderScenePass();
    boolean focus;

   // Selecting of graphics
   int OnSelect(int x, int y);
   void ProcessHits(GLint hits, GLuint buffer[]);

   // Track Ball Variables and Functions
#ifdef TRACKBALL
   int newModel;
   float lastquat[4];
   float curquat[4];
   void recalcModelView();
#endif
   int lightStartX;

   // Model Orientation Variables
   int starty;
   int startx;
   GLfloat angle2;
   GLfloat angle;
   
   // Camera Coordinates
   GLdouble centerX;
   GLdouble centerY;
   GLdouble centerZ;

   // View Orientation Variables
   GLdouble eyeX;
   GLdouble eyeY;
   GLdouble eyeZ;

   // Camera orientation variables
   GLdouble upX;
   GLdouble upY;
   GLdouble upZ;

   // Perspective variables
   GLdouble glFovy;
   GLdouble glNear;
   GLdouble glFar;
};

#ifndef _DEBUG  // debug version in AP210ViewerView.cpp
inline CAP210ViewerDoc* CAP210ViewerView::GetDocument()
   { return (CAP210ViewerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AP210VIEWERVIEW_H__9BE7D70F_0912_11D3_9B0D_0080AD428934__INCLUDED_)
