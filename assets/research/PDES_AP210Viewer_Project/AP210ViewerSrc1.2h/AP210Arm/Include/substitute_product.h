#ifndef SUBSTITUTE_PRODUCT_H
#define SUBSTITUTE_PRODUCT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API substitute_product:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 817};

   private:
      // Required attributes
      class ee_product *_defined_alternate_product[2000];
      class assembly_composition_relationship *_substitutable_component;

      // Optional attributes

   protected:
      substitute_product();

   public:
      ~substitute_product();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static substitute_product *InstanceOf(ARMObject *);
      static substitute_product *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static substitute_product *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
