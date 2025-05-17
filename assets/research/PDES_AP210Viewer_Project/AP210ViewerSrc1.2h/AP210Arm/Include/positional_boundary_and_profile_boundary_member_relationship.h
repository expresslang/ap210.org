#ifndef POSITIONAL_BOUNDARY_AND_PROFILE_BOUNDARY_MEMBER_RELATIONSHIP_H
#define POSITIONAL_BOUNDARY_AND_PROFILE_BOUNDARY_MEMBER_RELATIONSHIP_H

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

class AP210ARM_API positional_boundary_and_profile_boundary_member_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 125};

   private:
      // Required attributes
      class profile_related_positional_boundary *_offset_positional_boundary;
      class tolerance_zone_boundary_member *_base_profile_tolerance_zone_boundary_member;

      // Optional attributes

   protected:
      positional_boundary_and_profile_boundary_member_relationship();

   public:
      ~positional_boundary_and_profile_boundary_member_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static positional_boundary_and_profile_boundary_member_relationship *InstanceOf(ARMObject *);
      static positional_boundary_and_profile_boundary_member_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static positional_boundary_and_profile_boundary_member_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
