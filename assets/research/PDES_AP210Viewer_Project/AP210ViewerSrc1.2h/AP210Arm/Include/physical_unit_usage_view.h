#ifndef PHYSICAL_UNIT_USAGE_VIEW_H
#define PHYSICAL_UNIT_USAGE_VIEW_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_unit.h>

// Unions

// Enumerations

class AP210ARM_API physical_unit_usage_view:
public physical_unit
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 62};

   private:
      // Required attributes

      // Optional attributes
      class ee_material *_material[2000];

   protected:
      physical_unit_usage_view();

   public:
      ~physical_unit_usage_view();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_unit_usage_view *InstanceOf(ARMObject *);
      static physical_unit_usage_view *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_unit_usage_view *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
