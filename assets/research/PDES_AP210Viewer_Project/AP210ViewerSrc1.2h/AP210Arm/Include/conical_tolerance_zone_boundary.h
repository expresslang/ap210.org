#ifndef CONICAL_TOLERANCE_ZONE_BOUNDARY_H
#define CONICAL_TOLERANCE_ZONE_BOUNDARY_H

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

class AP210ARM_API conical_tolerance_zone_boundary:
public tolerance_zone_boundary
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 132};

   private:
      // Required attributes

      // Optional attributes

   protected:
      conical_tolerance_zone_boundary();

   public:
      ~conical_tolerance_zone_boundary();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static conical_tolerance_zone_boundary *InstanceOf(ARMObject *);
      static conical_tolerance_zone_boundary *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static conical_tolerance_zone_boundary *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
