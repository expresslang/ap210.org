// PackagedPart.h: interface for the Package class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PACKAGEDPART_H__610DC3E1_CAC0_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_PACKAGEDPART_H__610DC3E1_CAC0_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// object
#include "AP210Object.h"
#include "AP210ObjectList.h"

// ap210
#include "AP210LP.h"
#include "PhysicalUnit.h"
#include "Package.h"	// Added by ClassView

class PackagedPart : public AP210Object  
{
   friend class PackagedComponent;
   protected:
	   enum {typeID = baseID + 8};

   public:
      SdaiAppInstance PackagedPartRef;
      char *PartNumber;
      AP210ObjectList Points;
      int ItemFindNumber;

   private:
      // OpenGL display lists
      GLuint CapDisplayList;
      GLuint SideDisplayList;

   private:
	   PackagedPart(PWBDataBase *PWB,
                   SdaiAppInstance packaged_part);
   public:
	   static PackagedPart *Construct(PWBDataBase *PWB,
                                     SdaiAppInstance package);
	   virtual ~PackagedPart();

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static PackagedPart *DirectInstanceOf(AP210Object *);
      static PackagedPart *InstanceOf(AP210Object *);
#endif
   public:
	   Package *PackageRef;
	   int getPackagedComponentCount();
	   virtual void Select(AP210ObjectListItor *PCitor);
   };

#endif // !defined(AFX_PACKAGEDPART_H__610DC3E1_CAC0_11D3_8A99_0080AD428934__INCLUDED_)
