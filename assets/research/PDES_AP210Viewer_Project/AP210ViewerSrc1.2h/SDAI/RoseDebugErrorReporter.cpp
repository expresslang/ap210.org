// RoseDebugErrorReporter.cpp : implementation of the RoseDebugErrorReporter class
//

#include "stdafx.h"

#include "RoseDebugErrorReporter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// The only instance of this class
RoseDebugErrorReporter theErrorReporter;

RoseDebugErrorReporter::RoseDebugErrorReporter() : RoseErrorReporter()
{ 
	ROSE.error_reporter(this);
}

void RoseDebugErrorReporter::do_report(STR strPrefix, RoseError* pError, va_list ap)
{
	char buf[1024];				// Error message buffer

	f_errcode = pError->f_errcode;

	strcpy(buf, strPrefix);
	vsprintf(buf + strlen(buf), pError->f_message, ap);
	strcat(buf, "\r\n");

#ifdef USE_CONSOLE
	printf(buf);
#else
	// TODO: Implement your own error-reporting functionality here
#endif

#ifdef _DEBUG
	TRACE(buf);
#endif
}

void RoseDebugErrorReporter::do_quit(int err_code)
{
	AfxMessageBox("Fatal error. Can't proceed.",  MB_OK | MB_ICONSTOP | MB_APPLMODAL);

	// TODO: Abort the application here if needed
}
