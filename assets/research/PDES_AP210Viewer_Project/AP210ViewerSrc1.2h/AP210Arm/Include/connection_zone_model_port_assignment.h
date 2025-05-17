#ifndef CONNECTION_ZONE_MODEL_PORT_ASSIGNMENT_H
#define CONNECTION_ZONE_MODEL_PORT_ASSIGNMENT_H

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

class AP210ARM_API connection_zone_model_port_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 389};

   private:
      // Required attributes
      class connection_zone *_source;
      class analytical_model_port *_target;

      // Optional attributes

   protected:
      connection_zone_model_port_assignment();

   public:
      ~connection_zone_model_port_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static connection_zone_model_port_assignment *InstanceOf(ARMObject *);
      static connection_zone_model_port_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static connection_zone_model_port_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
