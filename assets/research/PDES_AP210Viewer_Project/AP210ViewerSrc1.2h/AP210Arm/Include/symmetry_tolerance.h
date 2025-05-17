#ifndef SYMMETRY_TOLERANCE_H
#define SYMMETRY_TOLERANCE_H

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

class AP210ARM_API symmetry_tolerance:
public geometric_tolerance_with_referenced_datum_system
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 821};

   private:
      // Required attributes

      // Optional attributes

   protected:
      symmetry_tolerance();

   public:
      ~symmetry_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static symmetry_tolerance *InstanceOf(ARMObject *);
      static symmetry_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static symmetry_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
