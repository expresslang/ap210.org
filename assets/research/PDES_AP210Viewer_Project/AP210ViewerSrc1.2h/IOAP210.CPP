// IOAP210.cpp: implementation of the IOAP210 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "AP210Viewer.h"
#include "IOAP210.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

class IOAP210 myidf(IDFSTEPEXT, IDFSTEPEXT);
class IOAP210 myap210arm(AP210ARMEXT, AP210ARMEXT);
class IOAP210 myap210;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IOAP210::IOAP210(char *extension, char *format) {
   Extension = strdup(extension);
   Format = strdup(format);
   registerAsExtensionHandler(Extension);
   registerAsReader(Format);
   registerAsWriter(Format);
   }

IOAP210::~IOAP210() {
   free(Extension);
   free(Format);
   }
