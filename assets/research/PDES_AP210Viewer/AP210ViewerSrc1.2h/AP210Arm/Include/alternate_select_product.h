#ifndef ALTERNATE_SELECT_PRODUCT_H
#define ALTERNATE_SELECT_PRODUCT_H

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

class AP210ARM_API alternate_select_product:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 90};

   private:
      // Required attributes
      class ee_product *_defined_alternate_product[2000];
      class ee_product *_defining_base_product;

      // Optional attributes
      class contract *_authorizing_agreement;

   protected:
      alternate_select_product();

   public:
      ~alternate_select_product();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static alternate_select_product *InstanceOf(ARMObject *);
      static alternate_select_product *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static alternate_select_product *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
