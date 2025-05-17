#ifndef START_ORDER_H
#define START_ORDER_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <work_order.h>

// Unions

// Enumerations

class AP210ARM_API start_order:
public work_order
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 792};

   private:
      // Required attributes

      // Optional attributes

   protected:
      start_order();

   public:
      ~start_order();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static start_order *InstanceOf(ARMObject *);
      static start_order *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static start_order *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
