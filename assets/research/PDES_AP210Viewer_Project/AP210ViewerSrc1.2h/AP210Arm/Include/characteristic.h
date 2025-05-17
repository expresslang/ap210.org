#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <standard_or_reference_document.h>
#include <numeric_or_non_numeric_select.h>

// Enumerations

class AP210ARM_API characteristic:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 34};

   private:
      // Required attributes
      STR _type_name;
      union standard_or_reference_document *_reference_document;
      union numeric_or_non_numeric_select *_property_value;

      // Optional attributes

   protected:
      characteristic();

   public:
      ~characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static characteristic *InstanceOf(ARMObject *);
      static characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
