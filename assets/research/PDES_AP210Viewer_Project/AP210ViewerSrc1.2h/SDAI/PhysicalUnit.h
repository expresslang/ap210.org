// PhysicalUnit.h: interface for the PhysicalUnit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHYSICALUNIT_H__81099D81_9235_11D4_8A9A_0080AD428934__INCLUDED_)
#define AFX_PHYSICALUNIT_H__81099D81_9235_11D4_8A9A_0080AD428934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PhysicalUnit;

#include "AP210GraphicObject.h"

// ap210
#include "AP210LP.h"

class PhysicalUnit : public AP210GraphicObject {
   friend class ComponentDefinition; 
   friend class PackagedComponent;

   protected:
      PhysicalUnit(PWBDataBase *PWB,
                   SdaiAppInstance packaged_part);
   protected:
      virtual ~PhysicalUnit();

   protected:
	  enum {typeID = baseID + 11};

   public:
      SdaiAppInstance PhysicalUnitRef;

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static PhysicalUnit *DirectInstanceOf(AP210Object *);
      static PhysicalUnit *InstanceOf(AP210Object *);
#endif
   protected:
      void getPoints(AP210ObjectList *lines);

   private:
      int ItemFindNumber;
      void SortLines(AP210ObjectList *lines);
      AP210LP *MatchLine(AP210ObjectList *lines, AP210Point *p);
	  SdaiAppInstance  getShape(SdaiModel AP210Model);

   public:
      char *PartNumber;
	  char *getPartNumber();
      static PhysicalUnit * Construct(PWBDataBase *PWB, SdaiAppInstance physical_unit);
	  void ReDraw(double Z = 0.0, double Base = 0.0);
	  double getConstructionHeight();
//	    virtual double getHeight() { return(0.5); }; // need to implement for a physical_unit
//      virtual void setHeight(double height) {}; // need to implement for a physical_unit
	  virtual double getHeight(); // need to implement for a physical_unit
      virtual void setHeight(double height); // need to implement for a physical_unit
      void Draw(double Base = 0);
	  virtual void Select(AP210ObjectListItor *PCitor);
   };

#endif // !defined(AFX_PHYSICALUNIT_H__81099D81_9235_11D4_8A9A_0080AD428934__INCLUDED_)
