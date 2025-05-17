#ifndef EXTERNALLY_DEFINED_EE_PRODUCT_DEFINITION_H
#define EXTERNALLY_DEFINED_EE_PRODUCT_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_product_definition.h>

// Unions

// Enumerations

class AP210ARM_API externally_defined_ee_product_definition:
public ee_product_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 542};

   private:
      // Required attributes
      STR _source;

      // Optional attributes

   protected:
      externally_defined_ee_product_definition();

   public:
      ~externally_defined_ee_product_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static externally_defined_ee_product_definition *InstanceOf(ARMObject *);
      static externally_defined_ee_product_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static externally_defined_ee_product_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
