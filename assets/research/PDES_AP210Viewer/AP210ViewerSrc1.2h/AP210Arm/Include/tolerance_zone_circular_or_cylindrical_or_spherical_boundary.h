#ifndef TOLERANCE_ZONE_CIRCULAR_OR_CYLINDRICAL_OR_SPHERICAL_BOUNDARY_H
#define TOLERANCE_ZONE_CIRCULAR_OR_CYLINDRICAL_OR_SPHERICAL_BOUNDARY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <tolerance_zone_boundary.h>

// Unions

// Enumerations

class AP210ARM_API tolerance_zone_circular_or_cylindrical_or_spherical_boundary:
public tolerance_zone_boundary
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 493};

   private:
      // Required attributes

      // Optional attributes

   protected:
      tolerance_zone_circular_or_cylindrical_or_spherical_boundary();

   public:
      ~tolerance_zone_circular_or_cylindrical_or_spherical_boundary();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone_circular_or_cylindrical_or_spherical_boundary *InstanceOf(ARMObject *);
      static tolerance_zone_circular_or_cylindrical_or_spherical_boundary *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone_circular_or_cylindrical_or_spherical_boundary *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
