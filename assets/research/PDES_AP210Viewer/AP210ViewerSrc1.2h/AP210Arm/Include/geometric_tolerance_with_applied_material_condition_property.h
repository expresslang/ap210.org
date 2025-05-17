#ifndef GEOMETRIC_TOLERANCE_WITH_APPLIED_MATERIAL_CONDITION_PROPERTY_H
#define GEOMETRIC_TOLERANCE_WITH_APPLIED_MATERIAL_CONDITION_PROPERTY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <geometric_tolerance.h>

// Unions

// Enumerations
#include <material_condition_property_names.h>

class AP210ARM_API geometric_tolerance_with_applied_material_condition_property:
public geometric_tolerance
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 246};

   private:
      // Required attributes
      material_condition_property_names::material_condition_property_names _applied_material_condition_property_name;

      // Optional attributes

   protected:
      geometric_tolerance_with_applied_material_condition_property();

   public:
      ~geometric_tolerance_with_applied_material_condition_property();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static geometric_tolerance_with_applied_material_condition_property *InstanceOf(ARMObject *);
      static geometric_tolerance_with_applied_material_condition_property *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static geometric_tolerance_with_applied_material_condition_property *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
