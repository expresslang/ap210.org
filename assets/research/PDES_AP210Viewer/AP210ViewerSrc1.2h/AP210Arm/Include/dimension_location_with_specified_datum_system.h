#ifndef DIMENSION_LOCATION_WITH_SPECIFIED_DATUM_SYSTEM_H
#define DIMENSION_LOCATION_WITH_SPECIFIED_DATUM_SYSTEM_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <dimensional_location.h>

// Unions

// Enumerations

class AP210ARM_API dimension_location_with_specified_datum_system:
public dimensional_location
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 499};

   private:
      // Required attributes
      class datum_system_defining_conditions_without_material_conditions *_referenced_datum_system_defining_conditions;

      // Optional attributes

   protected:
      dimension_location_with_specified_datum_system();

   public:
      ~dimension_location_with_specified_datum_system();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimension_location_with_specified_datum_system *InstanceOf(ARMObject *);
      static dimension_location_with_specified_datum_system *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimension_location_with_specified_datum_system *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
