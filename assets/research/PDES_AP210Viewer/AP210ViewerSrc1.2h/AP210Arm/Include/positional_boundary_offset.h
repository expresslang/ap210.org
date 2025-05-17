#ifndef POSITIONAL_BOUNDARY_OFFSET_H
#define POSITIONAL_BOUNDARY_OFFSET_H

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

class AP210ARM_API positional_boundary_offset:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 124};

   private:
      // Required attributes
      class positional_boundary_and_profile_boundary_member_relationship *_offset_boundary_relationship;
      class length_data_element *_tolerance_value;

      // Optional attributes

   protected:
      positional_boundary_offset();

   public:
      ~positional_boundary_offset();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static positional_boundary_offset *InstanceOf(ARMObject *);
      static positional_boundary_offset *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static positional_boundary_offset *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
