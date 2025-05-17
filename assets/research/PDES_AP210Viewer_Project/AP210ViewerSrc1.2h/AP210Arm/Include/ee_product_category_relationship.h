#ifndef EE_PRODUCT_CATEGORY_RELATIONSHIP_H
#define EE_PRODUCT_CATEGORY_RELATIONSHIP_H

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

class AP210ARM_API ee_product_category_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 515};

   private:
      // Required attributes
      class ee_product_category *_sub_category;
      class ee_product_category *_category;

      // Optional attributes

   protected:
      ee_product_category_relationship();

   public:
      ~ee_product_category_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_product_category_relationship *InstanceOf(ARMObject *);
      static ee_product_category_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_product_category_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
