#ifndef EE_PRODUCT_H
#define EE_PRODUCT_H

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

class AP210ARM_API ee_product:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 16};

   private:
      // Required attributes
      STR _product_nomenclature;
      STR _part_number;
      union person_organization *_design_owner;
      RoseBoolean _standard_product_indicator;

      // Optional attributes

   protected:
      ee_product();

   public:
      ~ee_product();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_product *InstanceOf(ARMObject *);
      static ee_product *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_product *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
