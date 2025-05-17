#ifndef PRODUCT_ASSOCIATION_H
#define PRODUCT_ASSOCIATION_H

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

class AP210ARM_API product_association:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 733};

   private:
      // Required attributes
      class ee_product_version *_relating_product;
      class ee_product_version *_related_product[2000];
      class ee_specification *_constraint_source;

      // Optional attributes

   protected:
      product_association();

   public:
      ~product_association();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static product_association *InstanceOf(ARMObject *);
      static product_association *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static product_association *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
