#ifndef AGGREGATE_CONNECTIVITY_REQUIREMENT_H
#define AGGREGATE_CONNECTIVITY_REQUIREMENT_H

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

class AP210ARM_API aggregate_connectivity_requirement:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 44};

   private:
      // Required attributes
      class functional_unit_network_node_definition *_connectivity_requirement;
      class design_composition_path *_design_definition_path;

      // Optional attributes

   protected:
      aggregate_connectivity_requirement();

   public:
      ~aggregate_connectivity_requirement();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static aggregate_connectivity_requirement *InstanceOf(ARMObject *);
      static aggregate_connectivity_requirement *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static aggregate_connectivity_requirement *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
