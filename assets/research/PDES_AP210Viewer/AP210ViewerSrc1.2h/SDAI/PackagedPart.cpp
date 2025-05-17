// Package.cpp: implementation of the Package class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
// drawing
#include "../AP210ViewerDoc.h"
#include "../AP210ViewerView.h"
#include "..\OpenGL\Tess.h"

#include "PackagedPart.h"
#include "PackagedComponent.h"
#include "ExtractGeometry.h"
#include "ap210_visualizer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
PackagedPart *PackagedPart::Construct(PWBDataBase *PWB,
                                      SdaiAppInstance packaged_part) {
   PackagedPart *pp;
   AP210ObjectListItor itor(&(PWB->PackagedParts));

   // look for an existing packaged part
   while((pp = (PackagedPart *)itor.NextInstanceOf(PackagedPart::TypeID())) != NULL) {
      if (pp->PackagedPartRef == packaged_part) {
         return pp;
         }
      }
   // create a new package
   pp = new PackagedPart(PWB, packaged_part);
   PWB->PackagedParts.Add(pp);
   return pp;
   }

PackagedPart::PackagedPart(PWBDataBase *PWB,
                           SdaiAppInstance packaged_part):
AP210Object(PWB) {
   static SdaiEntity PP = sdaiGetEntity(DataBase->AP210Model, "packaged_part");

   static SdaiEntity LDPP = sdaiGetEntity(DataBase->AP210Model, "library_defined_packaged_part");
   static SdaiAttr LDPP_ID = sdaiGetAttrDefinition(LDPP, "item_id");

   // demonstrates  Item/Find Number remove when implemented in IDF translator. 
   ItemFindNumber = DataBase->assignItemFindNumber();

   PackagedPartRef = packaged_part;

   if (sdaiIsInstanceOf(PackagedPartRef, PP)) {
      PartNumber = strdup(getPackagedPartPartNumber(DataBase->AP210Model, PackagedPartRef));
      }
   else if (sdaiIsInstanceOf(PackagedPartRef, LDPP)) {
      SdaiString id;

      sdaiGetAttr(PackagedPartRef, LDPP_ID, sdaiSTRING, &id);
      PartNumber = strdup(id);
      }
   else {
      TRACE("ERROR: #%s is not a packaged_part\n",
              _sdaiGetPart21Description(PackagedPartRef));
      PartNumber = strdup(_sdaiGetPart21Description(PackagedPartRef));
      }
   // build the package
   PackageRef = Package::Construct(PWB, 
                                   getPackagedPartPackage(DataBase->AP210Model, PackagedPartRef));
   }

PackagedPart::~PackagedPart() {
   free(PartNumber);
   }
int PackagedPart::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return AP210Object::DynamicType(ID);
   }
#ifdef INSTANCEOF
PackagedPart *PackagedPart::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(PackagedPart *)s;
   return 0;
   }
PackagedPart *PackagedPart::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(PackagedPart *)s;
   return 0;
   }
#endif
void PackagedPart::Select(AP210ObjectListItor *PCitor) {
TRACE("Selected %s\r\n", PartNumber);
   // Search for components 
   PackagedComponent *pc;
   PCitor->Reset();
   while((pc = (PackagedComponent *)PCitor->NextDirectInstanceOf(PackagedComponent::TypeID())) != NULL) {
      if (pc->PackagedPartRef == this) {
TRACE("  Selected %s\r\n", pc->getName());
         pc->Select();
         }
      }
   }

int PackagedPart::getPackagedComponentCount() {
   // count components
   AP210ObjectListItor PCitor(&(DataBase->ComponentDefinitions));
   int count = 0;
   PackagedComponent *pc;
   PCitor.Reset();
   while((pc = (PackagedComponent *)PCitor.NextDirectInstanceOf(PackagedComponent::TypeID())) != NULL) {
      if (pc->PackagedPartRef == this) {
          count++;
         }
      }
   return count;
   }
