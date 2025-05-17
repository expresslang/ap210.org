#ifndef MATING_CONNECTOR_COMPONENT_H
#define MATING_CONNECTOR_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <mating_connector_part.h>

// Enumerations

class AP210ARM_API mating_connector_component:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 605};

   private:
      // Required attributes
      union mating_connector_part *_definition;

      // Optional attributes
      STR _reference_designation;

   protected:
      mating_connector_component();

   public:
      ~mating_connector_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static mating_connector_component *InstanceOf(ARMObject *);
      static mating_connector_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static mating_connector_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
