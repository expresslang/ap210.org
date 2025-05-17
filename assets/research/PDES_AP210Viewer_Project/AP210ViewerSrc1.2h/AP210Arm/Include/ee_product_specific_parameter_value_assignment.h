#ifndef EE_PRODUCT_SPECIFIC_PARAMETER_VALUE_ASSIGNMENT_H
#define EE_PRODUCT_SPECIFIC_PARAMETER_VALUE_ASSIGNMENT_H

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

class AP210ARM_API ee_product_specific_parameter_value_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 517};

   private:
      // Required attributes
      class ee_product_related_product_category *_associated_product_category;
      class ee_product *_of_product;
      class parameter_assignment *_assigned_parameter;

      // Optional attributes

   protected:
      ee_product_specific_parameter_value_assignment();

   public:
      ~ee_product_specific_parameter_value_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_product_specific_parameter_value_assignment *InstanceOf(ARMObject *);
      static ee_product_specific_parameter_value_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_product_specific_parameter_value_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
