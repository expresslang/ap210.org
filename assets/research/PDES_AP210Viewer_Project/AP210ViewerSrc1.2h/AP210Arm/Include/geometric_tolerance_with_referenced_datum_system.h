#ifndef GEOMETRIC_TOLERANCE_WITH_REFERENCED_DATUM_SYSTEM_H
#define GEOMETRIC_TOLERANCE_WITH_REFERENCED_DATUM_SYSTEM_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <geometric_tolerance.h>

// Unions

// Enumerations

class AP210ARM_API geometric_tolerance_with_referenced_datum_system:
public geometric_tolerance
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 114};

   private:
      // Required attributes
      class datum_system_defining_conditions *_datum_system_definition;

      // Optional attributes

   protected:
      geometric_tolerance_with_referenced_datum_system();

   public:
      ~geometric_tolerance_with_referenced_datum_system();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static geometric_tolerance_with_referenced_datum_system *InstanceOf(ARMObject *);
      static geometric_tolerance_with_referenced_datum_system *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static geometric_tolerance_with_referenced_datum_system *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
