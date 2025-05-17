#ifndef ALTERNATE_PRODUCT_H
#define ALTERNATE_PRODUCT_H

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

class AP210ARM_API alternate_product:
public alternate_select_product
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 89};

   private:
      // Required attributes

      // Optional attributes

   protected:
      alternate_product();

   public:
      ~alternate_product();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static alternate_product *InstanceOf(ARMObject *);
      static alternate_product *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static alternate_product *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
