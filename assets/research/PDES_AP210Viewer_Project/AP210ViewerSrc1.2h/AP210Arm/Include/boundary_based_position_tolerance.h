#ifndef BOUNDARY_BASED_POSITION_TOLERANCE_H
#define BOUNDARY_BASED_POSITION_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <position_tolerance_with_referenced_datum_system.h>
#include <geometric_tolerance_with_applied_material_condition_property.h>

// Unions

// Enumerations

class AP210ARM_API boundary_based_position_tolerance:
public position_tolerance_with_referenced_datum_system,
public geometric_tolerance_with_applied_material_condition_property
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 243};

   private:
      // Required attributes

      // Optional attributes
      class profile_of_any_surface_tolerance_with_referenced_datum_system *_profile_control;

   protected:
      boundary_based_position_tolerance();

   public:
      ~boundary_based_position_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static boundary_based_position_tolerance *InstanceOf(ARMObject *);
      static boundary_based_position_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static boundary_based_position_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
