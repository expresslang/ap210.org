#ifndef DATUM_SYSTEM_DEFINING_CONDITIONS_WITH_MATERIAL_CONDITIONS_H
#define DATUM_SYSTEM_DEFINING_CONDITIONS_WITH_MATERIAL_CONDITIONS_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <datum_system_defining_conditions.h>

// Unions

// Enumerations

class AP210ARM_API datum_system_defining_conditions_with_material_conditions:
public datum_system_defining_conditions
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 425};

   private:
      // Required attributes
      class datum_feature_material_condition_property *_applied_material_condition_properties[2000];

      // Optional attributes

   protected:
      datum_system_defining_conditions_with_material_conditions();

   public:
      ~datum_system_defining_conditions_with_material_conditions();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_system_defining_conditions_with_material_conditions *InstanceOf(ARMObject *);
      static datum_system_defining_conditions_with_material_conditions *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_system_defining_conditions_with_material_conditions *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
