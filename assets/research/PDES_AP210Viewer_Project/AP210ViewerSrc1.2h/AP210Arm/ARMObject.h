#ifndef ARMOBJECT_H
#define ARMOBJECT_H
/*
 * $Id:$
 * Auth:
 */

#include <stdio.h>

class ARMObject {
   protected:
      enum {baseID = 2000};

   private:
      static int BaseOID;
      int OID;

   public:
      ARMObject();
      ~ARMObject();

      virtual int DynamicType(int ID);
      virtual int getTypeID() {return baseID;};
      static int TypeID() {return baseID;};
      virtual int getOID() {return OID;};
   };
#endif 
