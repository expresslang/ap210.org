#ifndef POSITIONAL_BOUNDARY_DEFINITION_H
#define POSITIONAL_BOUNDARY_DEFINITION_H

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

class AP210ARM_API positional_boundary_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 122};

   private:
      // Required attributes
      class positional_boundary *_defined_positional_boundary;

      // Optional attributes

   protected:
      positional_boundary_definition();

   public:
      ~positional_boundary_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static positional_boundary_definition *InstanceOf(ARMObject *);
      static positional_boundary_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static positional_boundary_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
