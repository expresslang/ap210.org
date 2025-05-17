#ifndef ANALYTICAL_MODEL_VECTOR_PORT_ASSIGNMENT_H
#define ANALYTICAL_MODEL_VECTOR_PORT_ASSIGNMENT_H

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

class AP210ARM_API analytical_model_vector_port_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 97};

   private:
      // Required attributes
      class scalar_terminal_definition *_assigned_functional_unit_terminals[2000];
      class analytical_model_vector_port *_assigned_analytical_model_vector_port;

      // Optional attributes

   protected:
      analytical_model_vector_port_assignment();

   public:
      ~analytical_model_vector_port_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static analytical_model_vector_port_assignment *InstanceOf(ARMObject *);
      static analytical_model_vector_port_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static analytical_model_vector_port_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
