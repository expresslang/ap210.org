#ifndef EE_PRODUCT_CATEGORY_H
#define EE_PRODUCT_CATEGORY_H

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

class AP210ARM_API ee_product_category:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 514};

   private:
      // Required attributes
      class model_parameter *_category_parameter[2000];
      class parameter_assignment *_category_specific_values[2000];
      STR _name;

      // Optional attributes
      class ee_document *_reference_document;

   protected:
      ee_product_category();

   public:
      ~ee_product_category();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_product_category *InstanceOf(ARMObject *);
      static ee_product_category *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_product_category *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
