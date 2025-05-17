#ifndef FUNCTIONAL_UNIT_TERMINAL_H
#define FUNCTIONAL_UNIT_TERMINAL_H

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

class AP210ARM_API functional_unit_terminal:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 565};

   private:
      // Required attributes
      class functional_unit *_accessed_functional_unit;
      class functional_unit_usage_view_terminal_definition *_definition;

      // Optional attributes

   protected:
      functional_unit_terminal();

   public:
      ~functional_unit_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_unit_terminal *InstanceOf(ARMObject *);
      static functional_unit_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_unit_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
