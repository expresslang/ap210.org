#ifndef LISTOFANALYTICAL_MODEL_SCALAR_PORT_H
#define LISTOFANALYTICAL_MODEL_SCALAR_PORT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API ListOfanalytical_model_scalar_port:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 823};

   private:
      // Required attributes
      class analytical_model_scalar_port *_analytical_model_scalar_port;

      // Optional attributes

   protected:
      ListOfanalytical_model_scalar_port();

   public:
      ~ListOfanalytical_model_scalar_port();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ListOfanalytical_model_scalar_port *InstanceOf(ARMObject *);
      static ListOfanalytical_model_scalar_port *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ListOfanalytical_model_scalar_port *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
