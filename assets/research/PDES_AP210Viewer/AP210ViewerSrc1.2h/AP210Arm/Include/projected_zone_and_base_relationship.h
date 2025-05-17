#ifndef PROJECTED_ZONE_AND_BASE_RELATIONSHIP_H
#define PROJECTED_ZONE_AND_BASE_RELATIONSHIP_H

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

class AP210ARM_API projected_zone_and_base_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 743};

   private:
      // Required attributes
      class physical_feature_or_part_template *_base_physical_feature;
      class tolerance_zone *_projected_zone;

      // Optional attributes

   protected:
      projected_zone_and_base_relationship();

   public:
      ~projected_zone_and_base_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static projected_zone_and_base_relationship *InstanceOf(ARMObject *);
      static projected_zone_and_base_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static projected_zone_and_base_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
