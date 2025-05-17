#ifndef AP210OBJECT_H
#define AP210OBJECT_H
/*
 * $Id: AP210Object.h,v 1.2 1999/07/17 18:59:56 keenan Exp $
 * Auth: Michael T. Keenan
 */

#include <stdio.h>

class packaged_component; // need to get rid of this.
class AP210ObjectList;
class AP210Line;
class AP210Point;
class PWBDataBase;

class AP210Object {
   protected:
      enum {baseID = 1000};
      PWBDataBase *DataBase;

   private:
      static int BaseOID;
      int OID;

   public:
      AP210Object(PWBDataBase *PWB);
      ~AP210Object();

      virtual int DynamicType(int ID);
      virtual int GetTypeID() {return baseID;};
      static int TypeID() {return baseID;};
      virtual int GetOID() {return OID;};
   };
#endif 
