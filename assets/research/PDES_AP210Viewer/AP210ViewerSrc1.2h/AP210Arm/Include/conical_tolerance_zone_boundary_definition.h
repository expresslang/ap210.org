#ifndef CONICAL_TOLERANCE_ZONE_BOUNDARY_DEFINITION_H
#define CONICAL_TOLERANCE_ZONE_BOUNDARY_DEFINITION_H

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

class AP210ARM_API conical_tolerance_zone_boundary_definition:
public tolerance_zone_boundary_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 383};

   private:
      // Required attributes
      class conical_tolerance_zone_boundary_diametrical_size_characteristic *_boundary_sizes[2000];

      // Optional attributes

   protected:
      conical_tolerance_zone_boundary_definition();

   public:
      ~conical_tolerance_zone_boundary_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static conical_tolerance_zone_boundary_definition *InstanceOf(ARMObject *);
      static conical_tolerance_zone_boundary_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static conical_tolerance_zone_boundary_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
