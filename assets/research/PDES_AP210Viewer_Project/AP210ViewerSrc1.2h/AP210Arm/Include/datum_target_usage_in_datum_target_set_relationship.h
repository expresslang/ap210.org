#ifndef DATUM_TARGET_USAGE_IN_DATUM_TARGET_SET_RELATIONSHIP_H
#define DATUM_TARGET_USAGE_IN_DATUM_TARGET_SET_RELATIONSHIP_H

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

class AP210ARM_API datum_target_usage_in_datum_target_set_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 430};

   private:
      // Required attributes
      class datum_target_set *_defined_datum_target_set;
      class datum_target *_used_datum_target;
      RoseInteger _datum_target_number;

      // Optional attributes

   protected:
      datum_target_usage_in_datum_target_set_relationship();

   public:
      ~datum_target_usage_in_datum_target_set_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_target_usage_in_datum_target_set_relationship *InstanceOf(ARMObject *);
      static datum_target_usage_in_datum_target_set_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_target_usage_in_datum_target_set_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
