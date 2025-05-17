#ifndef ASSEMBLY_ALTERNATE_PRODUCT_H
#define ASSEMBLY_ALTERNATE_PRODUCT_H

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

class AP210ARM_API assembly_alternate_product:
public alternate_select_product
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 192};

   private:
      // Required attributes
      class physical_unit_design_view *_basis_context;

      // Optional attributes

   protected:
      assembly_alternate_product();

   public:
      ~assembly_alternate_product();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_alternate_product *InstanceOf(ARMObject *);
      static assembly_alternate_product *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_alternate_product *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
