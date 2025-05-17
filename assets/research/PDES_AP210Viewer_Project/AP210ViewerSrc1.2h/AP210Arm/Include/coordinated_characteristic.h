#ifndef COORDINATED_CHARACTERISTIC_H
#define COORDINATED_CHARACTERISTIC_H

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

// Enumerations

class AP210ARM_API coordinated_characteristic:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 32};

   private:
      // Required attributes
      STR _type_name;
      class characteristic *_component_characteristic[2000];
      union standard_or_reference_document *_reference_document;

      // Optional attributes
      STR _dependent_environment;

   protected:
      coordinated_characteristic();

   public:
      ~coordinated_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static coordinated_characteristic *InstanceOf(ARMObject *);
      static coordinated_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static coordinated_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
