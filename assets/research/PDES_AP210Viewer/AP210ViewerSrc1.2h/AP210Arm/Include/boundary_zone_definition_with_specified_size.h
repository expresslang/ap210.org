#ifndef BOUNDARY_ZONE_DEFINITION_WITH_SPECIFIED_SIZE_H
#define BOUNDARY_ZONE_DEFINITION_WITH_SPECIFIED_SIZE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <tolerance_zone_boundary_definition.h>

// Unions

// Enumerations

class AP210ARM_API boundary_zone_definition_with_specified_size:
public tolerance_zone_boundary_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 250};

   private:
      // Required attributes
      class boundary_size_characteristic *_specified_boundary_size;

      // Optional attributes

   protected:
      boundary_zone_definition_with_specified_size();

   public:
      ~boundary_zone_definition_with_specified_size();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static boundary_zone_definition_with_specified_size *InstanceOf(ARMObject *);
      static boundary_zone_definition_with_specified_size *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static boundary_zone_definition_with_specified_size *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
