#ifndef SPECIFICATION_ALLOCATION_H
#define SPECIFICATION_ALLOCATION_H

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

class AP210ARM_API specification_allocation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 791};

   private:
      // Required attributes
      class ee_specification *_allocated_specification;
      union product_object_select *_target_product_object[2000];

      // Optional attributes

   protected:
      specification_allocation();

   public:
      ~specification_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static specification_allocation *InstanceOf(ARMObject *);
      static specification_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static specification_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
