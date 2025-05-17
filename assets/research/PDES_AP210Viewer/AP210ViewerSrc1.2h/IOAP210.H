// IOAP210.h: interface for the IOAP210 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IOAP210_H__EDB79D23_C552_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_IOAP210_H__EDB79D23_C552_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "IOSTEP.h"

// idf brd and lib extensions
#define IDFBRDEXT "brd"
#define IDFLIBEXT "lib"

// registered step extensions
#define IDFSTEPEXT "idfstp"
#define AP210ARMEXT "ap210arm"
#define AP210EXT "210"

ROSE_IO_DECLARE(IOAP210) : public IOSTEP  
{
private: 
   char *Extension;
   char *Format;
public:
	IOAP210(char *extension = AP210EXT, char *format = AP210EXT);
	virtual ~IOAP210();
	virtual char * format() { return (Format); }
	virtual char * extension () { return (Extension); }
};

#endif // !defined(AFX_IOAP210_H__EDB79D23_C552_11D3_8A99_0080AD428934__INCLUDED_)
