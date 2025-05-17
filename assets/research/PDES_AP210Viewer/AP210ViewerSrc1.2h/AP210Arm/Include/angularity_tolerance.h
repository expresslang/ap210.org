#ifndef ANGULARITY_TOLERANCE_H
#define ANGULARITY_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <geometric_tolerance_with_referenced_datum_system.h>

// Unions

// Enumerations

class AP210ARM_API angularity_tolerance:
public geometric_tolerance_with_referenced_datum_system
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 113};

   private:
      // Required attributes

      // Optional attributes

   protected:
      angularity_tolerance();

   public:
      ~angularity_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static angularity_tolerance *InstanceOf(ARMObject *);
      static angularity_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static angularity_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
