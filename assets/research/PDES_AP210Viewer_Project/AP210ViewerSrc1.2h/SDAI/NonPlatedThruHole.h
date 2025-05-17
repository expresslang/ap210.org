#ifndef NONPLATEDTHRUHOLE_H
#define NONPLATEDTHRUHOLE_H
/*
 * $Id: NonPlatedThruHole.h,v 1.3 1999/08/22 05:27:01 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "AP210Object.h"
#include "AP210ObjectList.h"
#include "ComponentDefinition.h"

class NonPlatedThruHole: public ComponentDefinition {
   protected:
      enum {typeID = baseID + 13};

   private:
      // "design" and "design usage" physical_units
      // of interconnect module. 
      SdaiAppInstance PhysicalDesignRef;
      SdaiAppInstance PhysicalDesignUsageRef;

   private:
      NonPlatedThruHole(PWBDataBase *PWB,
                        SdaiAppInstance pc,
                        AP210ObjectList *lines,
                        SdaiAppInstance unit,
                        SdaiAppInstance A2P_LOC);
   public:
      ~NonPlatedThruHole();

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static NonPlatedThruHole *DirectInstanceOf(AP210Object *);
      static NonPlatedThruHole *InstanceOf(AP210Object *);
#endif

   public:  
      static void Construct(PWBDataBase *PWB, SdaiNPL npthList);
      static NonPlatedThruHole *Construct(PWBDataBase *PWB, SdaiAppInstance PWBpu);
	   void setThickness(double thickness);
	   double getThickness();
      virtual void ReDraw(double Z = 0.0, double Base = 0.0);
      virtual void Draw(double Base = 0.0);
      double getConstructionThickness();
   };

#endif
