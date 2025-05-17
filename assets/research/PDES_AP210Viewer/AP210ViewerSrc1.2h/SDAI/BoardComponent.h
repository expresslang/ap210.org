#ifndef BOARDCOMPONENT_H
#define BOARDCOMPONENT_H
/*
 * $Id: BoardComponent.h,v 1.3 1999/08/22 05:27:01 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "AP210Object.h"
#include "AP210ObjectList.h"
#include "ComponentDefinition.h"

class BoardComponent: public ComponentDefinition {
   protected:
      enum {typeID = baseID + 6};

   private:
      // "design" and "design usage" physical_units
      // of interconnect module. 
      SdaiAppInstance PhysicalDesignRef;
      SdaiAppInstance PhysicalDesignUsageRef;

   private:
      BoardComponent(class PWBDataBase *PWB,
                     SdaiModel AP210Model,
                     SdaiAppInstance PWBpd,
                     SdaiAppInstance PWBpdu,
                     AP210ObjectList *lines);
   public:
      ~BoardComponent();

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static BoardComponent *DirectInstanceOf(AP210Object *);
      static BoardComponent *InstanceOf(AP210Object *);
#endif
   private: 
      void getDrilledHoles(SdaiModel AP210Model, SdaiNPL npthList);

   public:  
	   virtual void setName(CString name);
      static BoardComponent *Construct(PWBDataBase *PWB, SdaiModel AP210Model, SdaiAppInstance PWBpu);
	   void setThickness(double thickness);
	   double getThickness();
      virtual void ReDraw(double Z = 0.0, double Base = 0.0);
      virtual void Draw(double Base = 0.0);
      double getConstructionThickness();
   };

#endif
