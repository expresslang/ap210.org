#ifndef EE_PRODUCT_VERSION_H
#define EE_PRODUCT_VERSION_H

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
#include <person_organization.h>
#include <person_organization.h>

// Enumerations
#include <life_cycle_stage.h>

class AP210ARM_API ee_product_version:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 14};

   private:
      // Required attributes
      union person_organization *_creator;
      STR _revision_code;
      class ee_product *_versioned_item;
      class security_classification *_security_code;
      class ee_approval *_product_version_approval;
      life_cycle_stage::life_cycle_stage _life_cycle_status;

      // Optional attributes
      class contract *_authorizing_agreement;
      union person_organization *_product_supplier;
      union person_organization *_design_supplier;

   protected:
      ee_product_version();

   public:
      ~ee_product_version();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_product_version *InstanceOf(ARMObject *);
      static ee_product_version *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_product_version *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
