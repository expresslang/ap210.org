// Product.h: interface for the Product class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRODUCT_H__1D4C72E1_DBFB_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_PRODUCT_H__1D4C72E1_DBFB_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AP210Object.h"

class Product : public AP210Object  
{
   protected:
	   enum {typeID = baseID + 9};

   public:
      SdaiAppInstance ProductRef;
      char *PartNumber;

   public:
      Product(SdaiModel AP210Model, 
              PWBDataBase *PWB,
              SdaiAppInstance product);
      virtual ~Product();

   public:
	   static Product *Construct(SdaiModel AP210Model, 
                                PWBDataBase *PWB,
                                SdaiAppInstance product);

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static Product *DirectInstanceOf(AP210Object *);
      static Product *InstanceOf(AP210Object *);
};

#endif // !defined(AFX_PRODUCT_H__1D4C72E1_DBFB_11D3_8A99_0080AD428934__INCLUDED_)
