#ifndef DATUM_FEATURE_MATERIAL_CONDITION_PROPERTY_H
#define DATUM_FEATURE_MATERIAL_CONDITION_PROPERTY_H

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
#include <material_condition_property_names.h>

class AP210ARM_API datum_feature_material_condition_property:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 420};

   private:
      // Required attributes
      class datum_feature_usage_in_datum_system_relationship *_applied_to;
      material_condition_property_names::material_condition_property_names _name;

      // Optional attributes

   protected:
      datum_feature_material_condition_property();

   public:
      ~datum_feature_material_condition_property();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_feature_material_condition_property *InstanceOf(ARMObject *);
      static datum_feature_material_condition_property *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_feature_material_condition_property *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
