#ifndef SUPPLIED_PRODUCT_VERSION_H
#define SUPPLIED_PRODUCT_VERSION_H

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

class AP210ARM_API supplied_product_version:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 261};

   private:
      // Required attributes
      class ee_product_version *_supplied_product_version;
      class ee_approval *_supplied_product_version_approval;
      class organization *_supplier;

      // Optional attributes
      STR _supplier_part_number;

   protected:
      supplied_product_version();

   public:
      ~supplied_product_version();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static supplied_product_version *InstanceOf(ARMObject *);
      static supplied_product_version *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static supplied_product_version *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
