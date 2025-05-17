#ifndef FUNCTIONAL_UNIT_USAGE_VIEW_H
#define FUNCTIONAL_UNIT_USAGE_VIEW_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <functional_unit_definition.h>

// Unions

// Enumerations

class AP210ARM_API functional_unit_usage_view:
public functional_unit_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 56};

   private:
      // Required attributes

      // Optional attributes

   protected:
      functional_unit_usage_view();

   public:
      ~functional_unit_usage_view();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_unit_usage_view *InstanceOf(ARMObject *);
      static functional_unit_usage_view *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_unit_usage_view *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
