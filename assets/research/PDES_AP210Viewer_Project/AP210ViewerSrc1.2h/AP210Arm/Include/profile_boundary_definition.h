#ifndef PROFILE_BOUNDARY_DEFINITION_H
#define PROFILE_BOUNDARY_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <boundary_zone_definition_with_specified_size.h>

// Unions

// Enumerations

class AP210ARM_API profile_boundary_definition:
public boundary_zone_definition_with_specified_size
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 734};

   private:
      // Required attributes
      class true_profile *_basic_profile;

      // Optional attributes

   protected:
      profile_boundary_definition();

   public:
      ~profile_boundary_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static profile_boundary_definition *InstanceOf(ARMObject *);
      static profile_boundary_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static profile_boundary_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
