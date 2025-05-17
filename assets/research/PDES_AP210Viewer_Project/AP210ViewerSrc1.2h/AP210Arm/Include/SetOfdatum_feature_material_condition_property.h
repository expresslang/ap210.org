#ifndef SETOFDATUM_FEATURE_MATERIAL_CONDITION_PROPERTY_H
#define SETOFDATUM_FEATURE_MATERIAL_CONDITION_PROPERTY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfdatum_feature_material_condition_property:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 426};

   private:
      // Required attributes
      class datum_feature_material_condition_property *_datum_feature_material_condition_property;

      // Optional attributes

   protected:
      SetOfdatum_feature_material_condition_property();

   public:
      ~SetOfdatum_feature_material_condition_property();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfdatum_feature_material_condition_property *InstanceOf(ARMObject *);
      static SetOfdatum_feature_material_condition_property *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfdatum_feature_material_condition_property *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
