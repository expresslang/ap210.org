#ifndef ANALYTICAL_MODEL_PORT_H
#define ANALYTICAL_MODEL_PORT_H

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
#include <model_parameter_type.h>
#include <signal_flow_direction.h>

class AP210ARM_API analytical_model_port:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 91};

   private:
      // Required attributes
      class analytical_model *_accessed_analytical_model;
      STR _port_name;
      model_parameter_type::model_parameter_type _port_type;
      RoseBoolean _distributed_properties;

      // Optional attributes
      STR _unit_of_measure;
      signal_flow_direction::signal_flow_direction _nominal_signal_flow_direction;

   protected:
      analytical_model_port();

   public:
      ~analytical_model_port();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static analytical_model_port *InstanceOf(ARMObject *);
      static analytical_model_port *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static analytical_model_port *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
