#ifndef TEST_SELECT_PRODUCT_H
#define TEST_SELECT_PRODUCT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <alternate_select_product.h>

// Unions

// Enumerations

class AP210ARM_API test_select_product:
public alternate_select_product
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 827};

   private:
      // Required attributes

      // Optional attributes

   protected:
      test_select_product();

   public:
      ~test_select_product();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static test_select_product *InstanceOf(ARMObject *);
      static test_select_product *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static test_select_product *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
