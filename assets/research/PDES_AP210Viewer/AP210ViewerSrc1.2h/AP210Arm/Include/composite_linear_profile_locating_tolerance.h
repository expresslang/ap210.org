#ifndef COMPOSITE_LINEAR_PROFILE_LOCATING_TOLERANCE_H
#define COMPOSITE_LINEAR_PROFILE_LOCATING_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <profile_of_any_line_tolerance_with_referenced_datum_system.h>

// Unions

// Enumerations

class AP210ARM_API composite_linear_profile_locating_tolerance:
public profile_of_any_line_tolerance_with_referenced_datum_system
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 350};

   private:
      // Required attributes

      // Optional attributes

   protected:
      composite_linear_profile_locating_tolerance();

   public:
      ~composite_linear_profile_locating_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static composite_linear_profile_locating_tolerance *InstanceOf(ARMObject *);
      static composite_linear_profile_locating_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static composite_linear_profile_locating_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
