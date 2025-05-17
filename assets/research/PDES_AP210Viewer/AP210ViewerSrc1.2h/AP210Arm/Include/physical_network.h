#ifndef PHYSICAL_NETWORK_H
#define PHYSICAL_NETWORK_H

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

class AP210ARM_API physical_network:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 696};

   private:
      // Required attributes
      class component_terminal *_connectivity_requirement_element[2000];
      class join_relationship *_interconnect_module_network_topology_element[2000];
      STR _name;

      // Optional attributes

   protected:
      physical_network();

   public:
      ~physical_network();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_network *InstanceOf(ARMObject *);
      static physical_network *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_network *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
