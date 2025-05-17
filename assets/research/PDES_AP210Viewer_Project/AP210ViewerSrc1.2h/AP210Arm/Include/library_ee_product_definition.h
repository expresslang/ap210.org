#ifndef LIBRARY_EE_PRODUCT_DEFINITION_H
#define LIBRARY_EE_PRODUCT_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <library_item.h>
#include <ee_product_definition.h>

// Unions

// Enumerations

class AP210ARM_API library_ee_product_definition:
public library_item,
public ee_product_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 634};

   private:
      // Required attributes

      // Optional attributes

   protected:
      library_ee_product_definition();

   public:
      ~library_ee_product_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static library_ee_product_definition *InstanceOf(ARMObject *);
      static library_ee_product_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static library_ee_product_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
