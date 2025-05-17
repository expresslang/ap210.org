// Product.cpp: implementation of the Product class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Product.h"
#include "AP210ObjectList.h"
#include "../PWBDataBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Product::Product(SdaiModel AP210Model, 
                 PWBDataBase *PWB,
                 SdaiAppInstance product):
AP210Object(PWB) {
   static SdaiEntity P = sdaiGetEntity(AP210Model, "product");
   static SdaiAttr P_ID = sdaiGetAttrDefinition(P, "id");
   ProductRef = product;
   SdaiString partnumber;
   
   if (sdaiIsInstanceOf(ProductRef, P)) {
      sdaiGetAttr(ProductRef, P_ID, sdaiSTRING, &partnumber);
      PartNumber = strdup(partnumber);
      }
   else {
      TRACE("ERROR: #%s is not a product\n",
              _sdaiGetPart21Description(ProductRef));
      PartNumber = strdup(_sdaiGetPart21Description(ProductRef));
      }
   }

Product::~Product() {
   free(PartNumber);
   }
int Product::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return AP210Object::DynamicType(ID);
   }
Product *Product::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(Product *)s;
   return 0;
   }
Product *Product::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(Product *)s;
   return 0;
   }

Product *Product::Construct(SdaiModel AP210Model, 
                            PWBDataBase *PWB,
                            SdaiAppInstance product) {
   Product *p = NULL;
   AP210ObjectListItor itor(&(PWB->Products));

   if (product != sdaiNULL) {
      // look for an existing product
      while((p = (Product *)itor.NextInstanceOf(Product::TypeID())) != NULL) {
         if (p->ProductRef == product) {
            return p;
            }
         }
      // create a new product
      p = new Product(AP210Model, PWB, product);
      PWB->Products.Add(p);
      }
   return p;
   }

