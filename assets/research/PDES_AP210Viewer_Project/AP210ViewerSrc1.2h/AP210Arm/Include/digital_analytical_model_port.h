#ifndef DIGITAL_ANALYTICAL_MODEL_PORT_H
#define DIGITAL_ANALYTICAL_MODEL_PORT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <analytical_model_port.h>

// Unions

// Enumerations

class AP210ARM_API digital_analytical_model_port:
public analytical_model_port
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 496};

   private:
      // Required attributes

      // Optional attributes

   protected:
      digital_analytical_model_port();

   public:
      ~digital_analytical_model_port();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static digital_analytical_model_port *InstanceOf(ARMObject *);
      static digital_analytical_model_port *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static digital_analytical_model_port *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
