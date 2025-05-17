#ifndef ANALYTICAL_MODEL_SCALAR_PORT_H
#define ANALYTICAL_MODEL_SCALAR_PORT_H

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

class AP210ARM_API analytical_model_scalar_port:
public analytical_model_port
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 95};

   private:
      // Required attributes

      // Optional attributes

   protected:
      analytical_model_scalar_port();

   public:
      ~analytical_model_scalar_port();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static analytical_model_scalar_port *InstanceOf(ARMObject *);
      static analytical_model_scalar_port *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static analytical_model_scalar_port *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
