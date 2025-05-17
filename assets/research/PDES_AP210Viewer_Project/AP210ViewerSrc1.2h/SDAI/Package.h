// Package.h: interface for the Package class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PACKAGE_H__610DC3E1_CAC0_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_PACKAGE_H__610DC3E1_CAC0_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// object
#include "PhysicalUnit.h"
#include "AP210ObjectList.h"

class Package : public PhysicalUnit {
   friend class ComponentDefinition; 
   friend class PackagedComponent;

   protected:
	   enum {typeID = baseID + 7};

   public:
      SdaiAppInstance PackageRef;
//      char *PartNumber;

   private:
	   Package(PWBDataBase *PWB,
              SdaiAppInstance package);
   public:
	   static Package *Construct(PWBDataBase *PWB,
                                SdaiAppInstance package);
	   virtual ~Package();

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static Package *DirectInstanceOf(AP210Object *);
      static Package *InstanceOf(AP210Object *);
#endif
   private:
	  SdaiAppInstance  getShape(SdaiModel AP210Model);
      void OutputGlError(char* label);

   public:
	  virtual double getHeight();
      virtual void setHeight(double height);
	  virtual void Select(AP210ObjectListItor *PCitor);
   };

#endif // !defined(AFX_PACKAGE_H__610DC3E1_CAC0_11D3_8A99_0080AD428934__INCLUDED_)
