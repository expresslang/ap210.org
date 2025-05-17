#ifndef EXTERNALLY_DEFINED_DIMENSION_REPRESENTATION_H
#define EXTERNALLY_DEFINED_DIMENSION_REPRESENTATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <shape_dimension_representation.h>

// Unions

// Enumerations

class AP210ARM_API externally_defined_dimension_representation:
public shape_dimension_representation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 540};

   private:
      // Required attributes
      class external_definition *_definitions[2000];

      // Optional attributes
      class data_element *_dimension_value;

   protected:
      externally_defined_dimension_representation();

   public:
      ~externally_defined_dimension_representation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static externally_defined_dimension_representation *InstanceOf(ARMObject *);
      static externally_defined_dimension_representation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static externally_defined_dimension_representation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
