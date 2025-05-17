#ifndef PLANNED_CHARACTERISTIC_H
#define PLANNED_CHARACTERISTIC_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <requirement_allocation_select.h>

// Enumerations

class AP210ARM_API planned_characteristic:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 269};

   private:
      // Required attributes
      union requirement_allocation_select *_reference_requirement;
      class coordinated_characteristic *_planned_coordinated_characteristic;

      // Optional attributes

   protected:
      planned_characteristic();

   public:
      ~planned_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static planned_characteristic *InstanceOf(ARMObject *);
      static planned_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static planned_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
