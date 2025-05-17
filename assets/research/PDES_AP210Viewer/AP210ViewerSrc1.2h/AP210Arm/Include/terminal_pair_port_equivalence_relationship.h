#ifndef TERMINAL_PAIR_PORT_EQUIVALENCE_RELATIONSHIP_H
#define TERMINAL_PAIR_PORT_EQUIVALENCE_RELATIONSHIP_H

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

class AP210ARM_API terminal_pair_port_equivalence_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 822};

   private:
      // Required attributes
      class analytical_model_port *_equivalent_port;
      class analytical_model_scalar_port *_scalar_ports[2000];

      // Optional attributes

   protected:
      terminal_pair_port_equivalence_relationship();

   public:
      ~terminal_pair_port_equivalence_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static terminal_pair_port_equivalence_relationship *InstanceOf(ARMObject *);
      static terminal_pair_port_equivalence_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static terminal_pair_port_equivalence_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
