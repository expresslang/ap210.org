#ifndef PROFILE_BOUNDARY_DEFINITION_WITH_OFFSETS_H
#define PROFILE_BOUNDARY_DEFINITION_WITH_OFFSETS_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <profile_boundary_definition.h>

// Unions

// Enumerations

class AP210ARM_API profile_boundary_definition_with_offsets:
public profile_boundary_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 736};

   private:
      // Required attributes
      class tolerance_zone_boundary_member_offset *_boundary_offsets[2000];

      // Optional attributes

   protected:
      profile_boundary_definition_with_offsets();

   public:
      ~profile_boundary_definition_with_offsets();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static profile_boundary_definition_with_offsets *InstanceOf(ARMObject *);
      static profile_boundary_definition_with_offsets *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static profile_boundary_definition_with_offsets *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
