#ifndef COMPOSITE_SURFACE_PROFILE_REFINEMENT_TOLERANCE_H
#define COMPOSITE_SURFACE_PROFILE_REFINEMENT_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <profile_of_any_surface_tolerance.h>

// Unions
#include <locating_or_refinement_surface_profile_tolerance.h>

// Enumerations

class AP210ARM_API composite_surface_profile_refinement_tolerance:
public profile_of_any_surface_tolerance
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 360};

   private:
      // Required attributes
      union locating_or_refinement_surface_profile_tolerance *_refined_control;

      // Optional attributes

   protected:
      composite_surface_profile_refinement_tolerance();

   public:
      ~composite_surface_profile_refinement_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static composite_surface_profile_refinement_tolerance *InstanceOf(ARMObject *);
      static composite_surface_profile_refinement_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static composite_surface_profile_refinement_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
