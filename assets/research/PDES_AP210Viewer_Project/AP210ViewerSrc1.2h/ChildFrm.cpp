// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "AP210Viewer.h"

#include "ChildFrm.h"
#include "AP210ViewerDoc.h"
#include "AP210ViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP

   // Viewer specific commands
   ON_UPDATE_COMMAND_UI(ID_INDICATOR_REFDES, OnUpdateRefDes)
   ON_UPDATE_COMMAND_UI(ID_INDICATOR_PARTNUMBER, OnUpdatePartNumber)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
   ID_INDICATOR_REFDES,
   ID_INDICATOR_PARTNUMBER,
};
/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CMDIChildWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers

int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	if (!c_wndStatusBar.Create(this) ||
		!c_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	
	return 0;
}
// AP210 Viewer specific CMainFrame message handlers

/*
 * OnUpdateRefDes()
 *
 * Display the currently selected reference designators
 */
void CChildFrame::OnUpdateRefDes(CCmdUI *pCmdUI) {
   pCmdUI->Enable();
   PWBDataBase *pDoc = (PWBDataBase *)GetActiveDocument();

   if (pDoc != NULL) {
      pCmdUI->SetText(pDoc->SelectedRefDes);
      } 
   }
/*
 * OnUpdatePartNumber()
 *
 * Display the currently selected partnumber
 * This will only have a value if a single
 * packaged component is selected.
 */
void CChildFrame::OnUpdatePartNumber(CCmdUI *pCmdUI) {
   pCmdUI->Enable();
   PWBDataBase *pDoc = (PWBDataBase *)GetActiveDocument();

   if (pDoc != NULL) {
      pCmdUI->SetText(pDoc->SelectedPartNumber);
      } 
   }

/*
 * OnCreateClient()
 *
 * Setup the split panes.
 */
BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) {
	// TODO: Add your specialized code here and/or call the base class
	CMenu* pMenu = NULL;
   // create a splitter with 1 row, 2 columns
	if (!m_wndSplitter.CreateStatic(this, 1, 2)) {
		TRACE0("Failed to CreateStaticSplitter\n");
		return FALSE;
      }
   // add the first splitter pane - the default view in column 0
	if (!m_wndSplitter.CreateView(0, 0,
		RUNTIME_CLASS(CAP210ProdView), CSize(130, 50), pContext)) {
		TRACE0("Failed to create first pane\n");
		return FALSE;
      }
   // add the second splitter pane - an input view in column 1
	if (!m_wndSplitter.CreateView(0, 1,
		RUNTIME_CLASS(CAP210ViewerView), CSize(0, 0), pContext)) {
		TRACE0("Failed to create second pane\n");
		return FALSE;
      }
   // activate the input view
	SetActiveView((CView*)m_wndSplitter.GetPane(0,1));

   // return CMDIChildWnd::OnCreateClient(lpcs, pContext);
	return TRUE;
   }
