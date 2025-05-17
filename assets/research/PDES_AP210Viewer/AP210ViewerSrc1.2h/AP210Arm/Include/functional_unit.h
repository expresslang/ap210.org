#ifndef FUNCTIONAL_UNIT_H
#define FUNCTIONAL_UNIT_H

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

class AP210ARM_API functional_unit:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 59};

   private:
      // Required attributes
      class functional_unit_definition *_definition;
      STR _reference_designation;
      class functional_unit_network_definition *_composed_network;

      // Optional attributes
      class characteristic *_functional_property[2000];

   protected:
      functional_unit();

   public:
      ~functional_unit();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_unit *InstanceOf(ARMObject *);
      static functional_unit *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_unit *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
