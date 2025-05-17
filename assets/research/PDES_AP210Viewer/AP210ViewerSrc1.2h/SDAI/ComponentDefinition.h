#ifndef COMPONENTDEFINITION_H
#define COMPONENTDEFINITION_H
/*
 * $Id: ComponentDefinition.h,v 1.3 1999/08/22 05:27:01 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "AP210GraphicObject.h"
#include "AP210ObjectList.h"
#include "Package.h"

#include "AP210LP.h"
enum ComponentPlacement {Top, Bottom, Unplaced};

class ComponentDefinition: public AP210GraphicObject {
   friend class CAP210ViewerDoc; // for access to component in CAP210ViewerDoc::SetPartNumber
   friend class CPropertiesPage; // for access to component in CPropertiesPage::setValues
   friend class CComponentDefinitionSheet; // for access to PhysicalUnitRef in CComponentDefinitionSheet::setValues
   friend class PhysicalUnit; // for access to PhysicalUnitRef in PhysicalUnit::Select

   protected:
	   enum {typeID = baseID + 4};

   private:
      char *Name;      
   private:
      char *Id;
   public:

      // placement
      ComponentPlacement Side; // later this should be in PackagedComponent
   protected:
      double Height;

   private:
      // shape information not required after points created!
      // unless you want to edit them.
      AP210ObjectList Lines;

      // component in AP210 
      SdaiAppInstance Component;

   public:
      // Constructor for a PackagedComponent
      ComponentDefinition(class PWBDataBase *PWB,
                          SdaiAppInstance component);
      // Constructor for a board component
      ComponentDefinition(class PWBDataBase *PWB,
                          SdaiAppInstance component,
                          AP210ObjectList *lines);
      // Constructor for a component_definition (e.g. a Mechanical Part)
      ComponentDefinition(class PWBDataBase *PWB,
                          SdaiAppInstance component,
                          SdaiAppInstance unit,
                          SdaiAppInstance A2P_LOC);
      ~ComponentDefinition();

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static ComponentDefinition *DirectInstanceOf(AP210Object *);
      static ComponentDefinition *InstanceOf(AP210Object *);
#endif
   private:
      SdaiAppInstance PhysicalUnitAppRef;
      PhysicalUnit *PhysicalUnitRef;

      // WARNING: Duplicated in MountingRestrictArea
      //          Need to deal with this when MountingRestrictArea
      //          finished.
      void getPoints();
      void sortLines();
      AP210LP *ComponentDefinition::matchLine(AP210Point *p);

      // placement
      // keep to see if Rotation has changed.
      double Rotation;

   protected:
      int ItemFindNumber;

   protected:
	  void applyTranslationMatrix();
// These are two tighly coupled functions.
// The intent is that the caller will 
//    First call RenderCaps,
//    then change the color, and
//    then call RenderSides.
	   virtual void RenderCaps();
	   virtual void RenderSides();
      // modification
      virtual void setReDrawStatus(int status = 1);
      virtual int getReDrawStatus();

   protected: // private latter after PackageComponent constructor updated.
      SdaiAppInstance NauoRef;  // next_assembly_usage_occurance
      SdaiAppInstance ComponentUnitRef;
      SdaiAppInstance ComponentLocationRef;
      double m[16];  // OpenGL transformation matrix
      Package *PackageRef; // should turn into a pointer to a physical_unit C++ class.

   public:  
      void Trace();
      SdaiAppInstance getComponent() { return Component;};

      virtual SdaiAppInstance getComponentLocationRef() { return ComponentLocationRef;};
      virtual void deleteComponentLocationRef();
      virtual void createComponentLocationRef();

	   virtual char *getName();
	   virtual void setName(CString name);

	   virtual char *getId();
	   virtual void setId(CString id);

      virtual double getRotation();
      virtual void setRotation(double rotation);

      virtual double getY();
      virtual void setY(double y);

      virtual double getX();
      virtual void setX(double x);

      virtual CString getSurface();
      virtual void setSurface(CString surface);

      virtual int getItemFindNumber();

      BOOL getPlacementFixed();
      void setPlacementFixed(BOOL fixed);

      virtual void setSeatingPlane(double base);

      // Drawing functions
      virtual void Draw(double Z = 0.0);
      virtual void ReDraw(double Z = 0.0, double Base = 0.0);
      virtual GLuint getSideDisplayList();
      virtual GLuint getCapDisplayList();
   };

#endif
