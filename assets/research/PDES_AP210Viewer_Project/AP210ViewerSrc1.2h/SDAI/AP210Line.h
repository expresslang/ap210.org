#ifndef AP210LINE_H
#define AP210LINE_H
/*
 * $Id: AP210Line.h,v 1.1 1999/07/17 19:00:22 keenan Exp keenan $
 * Auth: Michael T. Keenan
 */

#include <stdio.h>

#include "AP210ObjectList.h"


class AP210Line: public AP210Object {
   protected:
      enum {typeID = baseID + 2};
      static int IdSeed;
   public:
      AP210Line(class PWBDataBase *PWB);
      ~AP210Line();

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static AP210Line *DirectInstanceOf(AP210Object *);
      static AP210Line *InstanceOf(AP210Object *);
#endif
   };
#endif 
