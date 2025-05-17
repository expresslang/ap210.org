#ifndef EE_PRODUCT_RELATED_PRODUCT_CATEGORY_H
#define EE_PRODUCT_RELATED_PRODUCT_CATEGORY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_product_category.h>

// Unions

// Enumerations

class AP210ARM_API ee_product_related_product_category:
public ee_product_category
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 516};

   private:
      // Required attributes
      class ee_product *_of_product[2000];

      // Optional attributes

   protected:
      ee_product_related_product_category();

   public:
      ~ee_product_related_product_category();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_product_related_product_category *InstanceOf(ARMObject *);
      static ee_product_related_product_category *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_product_related_product_category *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
