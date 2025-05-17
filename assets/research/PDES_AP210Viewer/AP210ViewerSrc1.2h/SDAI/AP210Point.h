#ifndef AP210POINT_H
#define AP210POINT_H
/*
 * $Id: AP210Point.h,v 1.2 1999/07/17 18:59:56 keenan Exp keenan $
 * Auth: Michael T. Keenan
 */
#include <stdio.h>
#include <math.h>

#include "sdai.h"

#include "AP210Object.h"
#include "AP210ObjectList.h"

class AP210LP;

class AP210Point: public AP210Object {
   protected:
      enum {typeID = baseID + 1};
   public:
      double X;
      double Y;
   private:
      AP210Point(class PWBDataBase *PWB, double x, double y);
      double DistanceToPoint(double x, double y);
   public:
      ~AP210Point();

      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};

#ifdef INSTANCEOF
      static AP210Point *DirectInstanceOf(AP210Object *);
      static AP210Point *InstanceOf(AP210Object *);
#endif
      static AP210Point *Construct(class PWBDataBase *PWB, 
                                  SdaiAppInstance p,
                                  double Factor = 1.0,
                                  double DeltaX = 0.0, double DeltaY = 0.0,
                                  // The intent for the defaults below to be for no rotation.
                                  double U11 = 1.0, double U12 = 0.0,
                                  double U21 = 0.0, double U22 = 1.0);
      static AP210Point *Construct(class PWBDataBase *PWB, 
                                  double orgx, double orgy,
                                  double Factor = 1.0,
                                  double DeltaX = 0.0, double DeltaY = 0.0,
                                  // The intent for the defaults below to be for no rotation.
                                  double U11 = 1.0, double U12 = 0.0,
                                  double U21 = 0.0, double U22 = 1.0);
      static AP210Point *FindPoint(class PWBDataBase *PWB, double x, double y);
   };
#endif 
