// RoseDebugErrorReporter.h : interface of the RoseDebugErrorReporter class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _RoseDebugErrorReporter_H
#define _RoseDebugErrorReporter_H

#include <rose.h>

class RoseDebugErrorReporter : public RoseErrorReporter
{

// Constructor / destructor
public:
	RoseDebugErrorReporter();	
	
// Operations

// Overrides
public:
	virtual void do_report(STR strPrefix, RoseError* pError, va_list ap);
	virtual void do_log (STR strPrefix, RoseError *pError, va_list ap) 
		{ 
			if (f_logfile != NULL) 
				RoseErrorReporter::do_log(strPrefix, pError, ap);
		}
	virtual void do_quit(int err_code);
};

#endif // _RoseDebugErrorReporter_H
