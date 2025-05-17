#ifndef DATUM_FEATURE_USAGE_IN_DATUM_SYSTEM_RELATIONSHIP_H
#define DATUM_FEATURE_USAGE_IN_DATUM_SYSTEM_RELATIONSHIP_H

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

class AP210ARM_API datum_feature_usage_in_datum_system_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 421};

   private:
      // Required attributes
      class datum_system *_established_datum_system;
      class datum_feature *_used_datum_feature;

      // Optional attributes

   protected:
      datum_feature_usage_in_datum_system_relationship();

   public:
      ~datum_feature_usage_in_datum_system_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_feature_usage_in_datum_system_relationship *InstanceOf(ARMObject *);
      static datum_feature_usage_in_datum_system_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_feature_usage_in_datum_system_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
