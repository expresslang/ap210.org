#ifndef EVALUATED_CHARACTERISTIC_H
#define EVALUATED_CHARACTERISTIC_H

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
#include <evaluation_type.h>

class AP210ARM_API evaluated_characteristic:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 268};

   private:
      // Required attributes
      class planned_characteristic *_evaluated_product_data;
      evaluation_type::evaluation_type _product_data_status;

      // Optional attributes
      class coordinated_characteristic *_product_characterization_data[2000];

   protected:
      evaluated_characteristic();

   public:
      ~evaluated_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static evaluated_characteristic *InstanceOf(ARMObject *);
      static evaluated_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static evaluated_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
