#ifndef CHANGE_ORDER_H
#define CHANGE_ORDER_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <work_order.h>

// Unions
#include <design_object_management_relationship_or_description.h>

// Enumerations

class AP210ARM_API change_order:
public work_order
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 263};

   private:
      // Required attributes
      union design_object_management_relationship_or_description *_adopted_solution;

      // Optional attributes

   protected:
      change_order();

   public:
      ~change_order();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static change_order *InstanceOf(ARMObject *);
      static change_order *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static change_order *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
