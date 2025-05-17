#ifndef COMPONENT_3D_LOCATION_H
#define COMPONENT_3D_LOCATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API component_3d_location:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 295};

   private:
      // Required attributes
      class axis_placement_3d *_transformation;
      RoseBoolean _placement_fixed;

      // Optional attributes

   protected:
      component_3d_location();

   public:
      ~component_3d_location();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_3d_location *InstanceOf(ARMObject *);
      static component_3d_location *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_3d_location *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
