#ifndef PART_DEVICE_TERMINAL_MODEL_PORT_ASSIGNMENT_H
#define PART_DEVICE_TERMINAL_MODEL_PORT_ASSIGNMENT_H

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

class AP210ARM_API part_device_terminal_model_port_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 678};

   private:
      // Required attributes
      class part_device_terminal *_internal_connection;
      class analytical_model_port *_internal_port;

      // Optional attributes

   protected:
      part_device_terminal_model_port_assignment();

   public:
      ~part_device_terminal_model_port_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_device_terminal_model_port_assignment *InstanceOf(ARMObject *);
      static part_device_terminal_model_port_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_device_terminal_model_port_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
