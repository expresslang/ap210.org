#ifndef PHYSICAL_UNIT_H
#define PHYSICAL_UNIT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_product_definition.h>

// Unions

// Enumerations

class AP210ARM_API physical_unit:
public ee_product_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 63};

   private:
      // Required attributes

      // Optional attributes
      class analytical_representation *_analytical_physical_unit_representation[2000];
      class technology *_unit_technology;
      class characteristic *_physical_device_characteristic[2000];
      class coordinated_characteristic *_physical_device_coordinated_characteristic[2000];
      class ee_requirement_occurrence *_design_requirement[2000];

   protected:
      physical_unit();

   public:
      ~physical_unit();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_unit *InstanceOf(ARMObject *);
      static physical_unit *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_unit *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
