#ifndef SIGNAL_SPECIFICATION_H
#define SIGNAL_SPECIFICATION_H

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

class AP210ARM_API signal_specification:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 558};

   private:
      // Required attributes
      class test_specification *_measurement_condition;
      class scalar_terminal_definition *_measurement_access_mechanism;
      class signal_property *_minimum_characteristic;
      class signal_property *_maximum_characteristic;
      class functional_unit_network_definition *_characterization_network;
      class functional_unit *_characterizing_functional_unit;

      // Optional attributes
      class scalar_terminal_definition *_reference_access_mechanism;

   protected:
      signal_specification();

   public:
      ~signal_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static signal_specification *InstanceOf(ARMObject *);
      static signal_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static signal_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
