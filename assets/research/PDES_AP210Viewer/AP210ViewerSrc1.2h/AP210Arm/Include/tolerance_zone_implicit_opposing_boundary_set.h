#ifndef TOLERANCE_ZONE_IMPLICIT_OPPOSING_BOUNDARY_SET_H
#define TOLERANCE_ZONE_IMPLICIT_OPPOSING_BOUNDARY_SET_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <tolerance_zone_opposing_boundary_set.h>

// Unions

// Enumerations

class AP210ARM_API tolerance_zone_implicit_opposing_boundary_set:
public tolerance_zone_opposing_boundary_set
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 848};

   private:
      // Required attributes

      // Optional attributes

   protected:
      tolerance_zone_implicit_opposing_boundary_set();

   public:
      ~tolerance_zone_implicit_opposing_boundary_set();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone_implicit_opposing_boundary_set *InstanceOf(ARMObject *);
      static tolerance_zone_implicit_opposing_boundary_set *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone_implicit_opposing_boundary_set *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
