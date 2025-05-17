#ifndef TOLERANCE_ZONE_PER_UNIT_SIZE_SPECIFICATION_H
#define TOLERANCE_ZONE_PER_UNIT_SIZE_SPECIFICATION_H

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

class AP210ARM_API tolerance_zone_per_unit_size_specification:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 841};

   private:
      // Required attributes
      class tolerance_zone *_specified_tolerance_zone;
      class length_data_element *_per_unit_size[2000];

      // Optional attributes

   protected:
      tolerance_zone_per_unit_size_specification();

   public:
      ~tolerance_zone_per_unit_size_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone_per_unit_size_specification *InstanceOf(ARMObject *);
      static tolerance_zone_per_unit_size_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone_per_unit_size_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
