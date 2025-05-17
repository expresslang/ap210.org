#ifndef AP210LP_H
#define AP210LP_H
/*
 * $Id: AP210LP.h,v 1.1 1999/07/17 19:00:22 keenan Exp keenan $
 * Auth: Michael T. Keenan
 */
#include <stdio.h>
#include <math.h>

#include "AP210Point.h"
#include "AP210Line.h"
#include "AP210ObjectList.h"

#include "MathUtility.h"

enum intersects {DoIntersect, DoMeet, Collinear, DontIntersect};

class AP210LP: public AP210Line {
   protected:
      enum {typeID = baseID + 3};
      AP210Point *Start;
      AP210Point *End;

   private:
      AP210LP(class PWBDataBase *PWB, AP210Point *p1, AP210Point *p2);
   public:
      ~AP210LP();

      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static AP210LP *DirectInstanceOf(AP210Object *);
      static AP210LP *InstanceOf(AP210Object *);
#endif
      static AP210LP *Construct(class PWBDataBase *PWB, AP210Point *p1, AP210Point *p2);
      AP210Point *EndPoint() {return End;};
      static AP210LP *FindLine(class PWBDataBase *PWB, AP210Point *p1, AP210Point *p2);
      double MaxX() {return Max(Start->X, End->X); };
      double MaxY() {return Max(Start->Y, End->Y); };
#if 0
      double MinX() {return Min(Start->X, End->X); };
      double MinY() {return Min(Start->Y, End->Y); };
#endif
      void SortEndPoints();
      AP210Point *StartPoint() {return Start;};
      void SwapPoints();
   };
#endif 
