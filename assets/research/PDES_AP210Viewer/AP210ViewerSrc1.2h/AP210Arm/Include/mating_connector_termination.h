#ifndef MATING_CONNECTOR_TERMINATION_H
#define MATING_CONNECTOR_TERMINATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <packaged_or_printed_terminal.h>

// Enumerations

class AP210ARM_API mating_connector_termination:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 652};

   private:
      // Required attributes
      union packaged_or_printed_terminal *_definition;
      class mating_connector_component *_accessed_connector;
      STR _name;

      // Optional attributes
      class ee_requirement_occurrence *_signal_definition;

   protected:
      mating_connector_termination();

   public:
      ~mating_connector_termination();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static mating_connector_termination *InstanceOf(ARMObject *);
      static mating_connector_termination *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static mating_connector_termination *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
