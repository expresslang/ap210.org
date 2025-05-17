// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__9BE7D707_0912_11D3_9B0D_0080AD428934__INCLUDED_)
#define AFX_STDAFX_H__9BE7D707_0912_11D3_9B0D_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions like CFormView, CSplitterWnd
#include <afxdisp.h>        // MFC OLE automation classes
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

// C runtime
#include <math.h>

// Open GL 
#include <wingdi.h>     // Interface to GDI for OPENGL
#include "gl/gl.h" 		// OPENGL
#include "gl/glu.h" 		// OPENGL
#include <GL/glut.h>    // OpenGL Utility Toolkit header
#ifdef TRACKBALL
#include "OpenGL/TrackBall.h" // TrackBall support
#endif

/* Some <math.h> files do not define M_PI... */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// StepTools/SDAI
#include "rose.h"
#include "sdai.h"
#include "Sdai/SdaiUtility.h"
#include "Sdai/UnitUtility.h"

// AP210 specific 
#include "Sdai/AP210SdaiModel.h"
#include "Sdai/SdaiStoredProceedures.h"

// IDF Specific
#include "IDF2AP210/PopulateBaseCircle.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__9BE7D707_0912_11D3_9B0D_0080AD428934__INCLUDED_)
