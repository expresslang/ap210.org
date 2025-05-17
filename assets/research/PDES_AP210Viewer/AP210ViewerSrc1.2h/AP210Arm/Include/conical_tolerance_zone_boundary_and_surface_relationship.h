#ifndef CONICAL_TOLERANCE_ZONE_BOUNDARY_AND_SURFACE_RELATIONSHIP_H
#define CONICAL_TOLERANCE_ZONE_BOUNDARY_AND_SURFACE_RELATIONSHIP_H

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

class AP210ARM_API conical_tolerance_zone_boundary_and_surface_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 131};

   private:
      // Required attributes
      class conical_tolerance_zone_boundary *_sized_tolerance_zone_boundary;
      class physical_feature_or_part_template *_terminating_surface;

      // Optional attributes

   protected:
      conical_tolerance_zone_boundary_and_surface_relationship();

   public:
      ~conical_tolerance_zone_boundary_and_surface_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static conical_tolerance_zone_boundary_and_surface_relationship *InstanceOf(ARMObject *);
      static conical_tolerance_zone_boundary_and_surface_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static conical_tolerance_zone_boundary_and_surface_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
