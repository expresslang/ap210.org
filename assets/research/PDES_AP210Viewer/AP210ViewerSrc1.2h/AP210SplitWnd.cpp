// AP210SplitWnd.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "AP210SplitWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAP210SplitWnd

CAP210SplitWnd::CAP210SplitWnd()
{
}

CAP210SplitWnd::~CAP210SplitWnd()
{
}


BEGIN_MESSAGE_MAP(CAP210SplitWnd, CSplitterWnd)
	//{{AFX_MSG_MAP(CAP210SplitWnd)
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CAP210SplitWnd message handlers

BOOL CAP210SplitWnd::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default

   // CSplitterWnd::OnMouseWheel causes a debug assert failure because
   // the CAP210ProdView is not a child of CScrollView. We are doing
   // our own thing with the mouse wheel so we don't need it at this
   // time.  In th futrue we might need to implement something here
   // that would be a version of CSplitterWnd::OnMouseWheel that
   // would filter out CAP210ProdView	
//	return CSplitterWnd::OnMouseWheel(nFlags, zDelta, pt);

   // return TRUE because we are happy!
	return TRUE;
}
