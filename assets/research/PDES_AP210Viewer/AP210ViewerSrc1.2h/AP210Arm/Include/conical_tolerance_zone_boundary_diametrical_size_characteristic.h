#ifndef CONICAL_TOLERANCE_ZONE_BOUNDARY_DIAMETRICAL_SIZE_CHARACTERISTIC_H
#define CONICAL_TOLERANCE_ZONE_BOUNDARY_DIAMETRICAL_SIZE_CHARACTERISTIC_H

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

class AP210ARM_API conical_tolerance_zone_boundary_diametrical_size_characteristic:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 130};

   private:
      // Required attributes
      class conical_tolerance_zone_boundary_and_surface_relationship *_sized_boundary_at_surface;
      class length_data_element *_tolerance_value;

      // Optional attributes

   protected:
      conical_tolerance_zone_boundary_diametrical_size_characteristic();

   public:
      ~conical_tolerance_zone_boundary_diametrical_size_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static conical_tolerance_zone_boundary_diametrical_size_characteristic *InstanceOf(ARMObject *);
      static conical_tolerance_zone_boundary_diametrical_size_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static conical_tolerance_zone_boundary_diametrical_size_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
