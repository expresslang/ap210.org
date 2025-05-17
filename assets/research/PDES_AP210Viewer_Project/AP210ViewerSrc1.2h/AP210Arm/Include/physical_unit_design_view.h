#ifndef PHYSICAL_UNIT_DESIGN_VIEW_H
#define PHYSICAL_UNIT_DESIGN_VIEW_H

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

class AP210ARM_API physical_unit_design_view:
public physical_unit
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 193};

   private:
      // Required attributes
      class physical_unit_usage_view *_usage_view;

      // Optional attributes

   protected:
      physical_unit_design_view();

   public:
      ~physical_unit_design_view();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_unit_design_view *InstanceOf(ARMObject *);
      static physical_unit_design_view *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_unit_design_view *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
