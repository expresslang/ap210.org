// AP210Viewer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "AP210Viewer.h"

// MFC
#include "MainFrm.h"
#include "ChildFrm.h"
#include "MultiFileMultiDocTemplate.h"
#include "AP210ViewerDoc.h"
#include "AP210ViewerView.h"
#include "AP210DocManager.h"
#include "IDFDoc.h"
#include "ComponentPlacementRestriction.h"

// OpenGl
#include "OpenGL/tess.h"

// STEP
SdaiSession mySession;
SdaiRep myRepository;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// used send errors to Debug window.
void SdaiMFCDebugErrorHandler(SdaiErrorCode errorcode)
   {
   // this function should process all errors
      TRACE("SDAI Error: %s.\n", _sdaiGetErrorName(errorcode));
   }
/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerApp

BEGIN_MESSAGE_MAP(CAP210ViewerApp, CWinApp)
	//{{AFX_MSG_MAP(CAP210ViewerApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_READMEFILE, OnReadmefile)
	ON_COMMAND(ID_FILE_PREFERENCES, OnFilePreferences)
	ON_COMMAND(ID_FILE_OPEN_READONLY, OnFileOpenReadonly)
	ON_COMMAND(ID_IMPORT_IDF, OnImportIdf)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerApp construction

CAP210ViewerApp::CAP210ViewerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerApp destructor
CAP210ViewerApp::~CAP210ViewerApp()

{
	// TODO: add destruction code here,
	// Place all significant initialization in InitInstance
   // shutdown SDAI
   // MTK Jan 9, 2000 I think I need to look in myRepository
   // and delete any models here, this may be the cause of
   // the memory leak I've been observing.
TRACE0("Close Repository\n");
   sdaiCloseRepository(myRepository);
TRACE0("Close Session\n");
   sdaiCloseSession(mySession);
}
/////////////////////////////////////////////////////////////////////////////
// The one and only CAP210ViewerApp object

CAP210ViewerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerApp initialization

BOOL CAP210ViewerApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored
   // in HKEY_CURRENT_USER
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("EMPilot"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

    // AP210 files with various extensions
    //(*.stp; *.p21;*step;*.pdes, *.210)
   AP210AIMMultiDocTemplate = new CMultiFileMultiDocTemplate(
		IDR_AP210VTYPE,
		RUNTIME_CLASS(CAP210ViewerDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CAP210ViewerView));
	AddDocTemplate(AP210AIMMultiDocTemplate);

   // Don't add the ARM doc template since we don't readit.
	AP210ARMDocTemplate = new CMultiFileMultiDocTemplate(
		IDR_AP210ARM,
		RUNTIME_CLASS(CAP210ViewerDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CAP210ViewerView));

   // Don't add the AIM doc template *.210
   // since we don't read it with this template
   // because it is in AP210AIMMultiDocTemplate
	AP210AIMDocTemplate = new CMultiFileMultiDocTemplate(
		IDR_AP210AIM,
		RUNTIME_CLASS(CAP210ViewerDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CAP210ViewerView));

    // IDF files *.brd, loads *.lib also.
	IDFDocTemplate = new CMultiDocTemplate(
		IDR_IDF, // need to add this
		RUNTIME_CLASS(CIDFDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CAP210ViewerView));
	AddDocTemplate(IDFDocTemplate);

   // IDF Step files *.idfstp
	IDFStepDocTemplate = new CMultiFileMultiDocTemplate(
		IDR_IDFSTP,
		RUNTIME_CLASS(CIDFDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CAP210ViewerView));
	AddDocTemplate(IDFStepDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;

    // set the ShellCommand to what I want.
    cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

    // Intialize STEP Tools
    // set location of Windows registry information
   TRACE0("Setting registry key.\n");
   TRACE0(rose_getenv_registry_key()); TRACE0("\n");

   //NEED to check this if it fails it is a bad error.
   rose_setenv_registry_key(AP210VIEWER_MACHINE_REGISTRY);
   TRACE0(rose_getenv_registry_key()); TRACE0("\n");

   // Install a custom error handler.
   sdaiSetErrorHandler (SdaiMFCDebugErrorHandler);

  // avoids copious, but potentially helpful messages
#ifdef SILENT
   _sdaiVerbose (sdaiFALSE);
#endif

   // clear the error code.
   sdaiErrorQuery();

   // start SDAI session
TRACE0("Open Session\n");
   mySession = sdaiOpenSession();
   if(sdaiErrorQuery()) {
      TRACE0("Cannot create session\n");
      return FALSE;
      }
   /* open STEP repository */
TRACE0("Open Repository\n");
   myRepository = sdaiOpenRepositoryBN (mySession, "step");
   if(sdaiErrorQuery()) {
      TRACE0("No repository\n");
      return FALSE;
      }    
	return TRUE;
   }

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CAP210ViewerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerApp commands


void CAP210ViewerApp::OnReadmefile()  {
   long flag;
   TCHAR path[512];
   TCHAR command[1024];
   DWORD dwKeyDataType;
   DWORD dwDataBufSize = sizeof(path);
   HKEY hKey;
	// TODO: Add your command handler code here
   if ((flag = RegOpenKeyEx(HKEY_LOCAL_MACHINE,  _T(AP210VIEWER_MACHINE_REGISTRY),
				0, KEY_QUERY_VALUE, &hKey)) == ERROR_SUCCESS) {

      if ((flag = RegQueryValueEx(hKey, _T("AP210_VIEWER_HOME"), NULL, &dwKeyDataType,
					(LPBYTE) &path, &dwDataBufSize)) == ERROR_SUCCESS) {
         sprintf(command, "notepad.exe %s\\readme.txt", path);
	      system(command);
			}
      RegCloseKey(hKey);
      }
   if (flag != ERROR_SUCCESS) {
      LPVOID lpMsgBuf;

      FormatMessage( 
         FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
         NULL,
         flag,
         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
         (LPTSTR) &lpMsgBuf,
         0,
         NULL 
         );

      // Display the string.
      MessageBox( NULL, (const char *)lpMsgBuf, "View Readme.txt", MB_OK|MB_ICONINFORMATION );

      // Free the buffer.
      LocalFree( lpMsgBuf );
		}
   } 

BOOL CAP210ViewerApp::InitApplication() {
	// TODO: Add your specialized code here and/or call the base class

   // set the Document Manager to my subclass.
   m_pDocManager = new AP210DocManager;

   // Setup OpenGL Tessellation
   InitTess();

	return CWinApp::InitApplication();
   }

void CAP210ViewerApp::OnFilePreferences() {
	// TODO: Add your command handler code here
  }

void CAP210ViewerApp::OnFileOpenReadonly() {
	// TODO: Add your command handler code here
	ASSERT(m_pDocManager != NULL);
	((AP210DocManager *)m_pDocManager)->OnFileOpenReadonly();
   }

void CAP210ViewerApp::OnImportIdf() {
	// TODO: Add your command handler code here
	ASSERT(m_pDocManager != NULL);
	((AP210DocManager *)m_pDocManager)->OnImportIdf();
   }
