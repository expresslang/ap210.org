#ifndef PRINTED_CONNECTOR_COMPONENT_INTERFACE_TERMINAL_H
#define PRINTED_CONNECTOR_COMPONENT_INTERFACE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <component_feature.h>

// Unions

// Enumerations

class AP210ARM_API printed_connector_component_interface_terminal:
public component_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 327};

   private:
      // Required attributes

      // Optional attributes

   protected:
      printed_connector_component_interface_terminal();

   public:
      ~printed_connector_component_interface_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_connector_component_interface_terminal *InstanceOf(ARMObject *);
      static printed_connector_component_interface_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_connector_component_interface_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
