#ifndef PROFILE_RELATED_POSITIONAL_BOUNDARY_DEFINITION_H
#define PROFILE_RELATED_POSITIONAL_BOUNDARY_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <positional_boundary_definition.h>

// Unions

// Enumerations

class AP210ARM_API profile_related_positional_boundary_definition:
public positional_boundary_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 121};

   private:
      // Required attributes
      class positional_boundary_offset *_boundary_offset;

      // Optional attributes

   protected:
      profile_related_positional_boundary_definition();

   public:
      ~profile_related_positional_boundary_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static profile_related_positional_boundary_definition *InstanceOf(ARMObject *);
      static profile_related_positional_boundary_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static profile_related_positional_boundary_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
