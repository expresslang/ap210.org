#ifndef PACKAGEDCOMPONENT_H
#define PACKAGEDCOMPONENT_H
/*
 * $Id: PackagedComponent.h,v 1.3 1999/08/22 05:27:01 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "AP210Object.h"
#include "AP210ObjectList.h"
#include "Package.h"
#include "PackagedPart.h"
#include "ComponentDefinition.h"

#include "AP210LP.h"

class PackagedComponent: public ComponentDefinition {
   friend Package; // for access to PackageRef in Package::Select
   friend PackagedPart; // for access to PackagedPartRef in PackagedPart::Select
   friend class CComponentPropertiesSheet; // for access to PackagedPartRef in CComponentPropertiesSheet::setValues
   protected:
      enum {typeID = baseID + 5};

   private:
	  virtual GLuint getSideDisplayList();
	  virtual GLuint getCapDisplayList();
	  virtual int getReDrawStatus();
      PackagedPart *PackagedPartRef;

   public:
      PackagedComponent(class PWBDataBase *PWB,
                        SdaiAppInstance pc,
                        SdaiAppInstance unit,
                        SdaiAppInstance A2P_LOC);
      ~PackagedComponent();

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static PackagedComponent *DirectInstanceOf(AP210Object *);
      static PackagedComponent *InstanceOf(AP210Object *);
#endif
   protected:
      virtual void setReDrawStatus(int status = 0);
      virtual void OutputGLError(char *label);
// These are two tighly coupled functions.
// The intent is that the caller will 
//    First call RenderCaps,
//    then change the color, and
//    then call RenderSides.
      virtual void RenderCaps();
      virtual void RenderSides();
   public:  
      virtual void ReDraw(double Z = 0.0, double Base = 0.0);
   }; 

#endif
