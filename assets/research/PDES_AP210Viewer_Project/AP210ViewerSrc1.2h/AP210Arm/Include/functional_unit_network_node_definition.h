#ifndef FUNCTIONAL_UNIT_NETWORK_NODE_DEFINITION_H
#define FUNCTIONAL_UNIT_NETWORK_NODE_DEFINITION_H

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

class AP210ARM_API functional_unit_network_node_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 45};

   private:
      // Required attributes
      class functional_unit_network_definition *_associated_functional_unit_definition;
      STR _functional_unit_network_node_name;

      // Optional attributes

   protected:
      functional_unit_network_node_definition();

   public:
      ~functional_unit_network_node_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_unit_network_node_definition *InstanceOf(ARMObject *);
      static functional_unit_network_node_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_unit_network_node_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
