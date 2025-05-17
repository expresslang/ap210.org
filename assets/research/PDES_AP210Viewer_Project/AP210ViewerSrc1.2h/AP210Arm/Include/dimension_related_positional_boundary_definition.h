#ifndef DIMENSION_RELATED_POSITIONAL_BOUNDARY_DEFINITION_H
#define DIMENSION_RELATED_POSITIONAL_BOUNDARY_DEFINITION_H

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

class AP210ARM_API dimension_related_positional_boundary_definition:
public positional_boundary_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 504};

   private:
      // Required attributes
      class positional_boundary_member_definition *_characterized_boundary_member_definitions[2000];

      // Optional attributes

   protected:
      dimension_related_positional_boundary_definition();

   public:
      ~dimension_related_positional_boundary_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimension_related_positional_boundary_definition *InstanceOf(ARMObject *);
      static dimension_related_positional_boundary_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimension_related_positional_boundary_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
