#ifndef EE_PRODUCT_CONFIGURATION_H
#define EE_PRODUCT_CONFIGURATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <person_organization.h>

// Enumerations

class AP210ARM_API ee_product_configuration:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 272};

   private:
      // Required attributes
      union person_organization *_configuration_manager;
      STR _item_id;
      class ee_approval *_product_configuration_approval;
      class ee_product_model *_model_of_product;
      STR _phase_of_product;

      // Optional attributes
      class ee_product_version *_satisfying_product[2000];

   protected:
      ee_product_configuration();

   public:
      ~ee_product_configuration();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_product_configuration *InstanceOf(ARMObject *);
      static ee_product_configuration *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_product_configuration *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
