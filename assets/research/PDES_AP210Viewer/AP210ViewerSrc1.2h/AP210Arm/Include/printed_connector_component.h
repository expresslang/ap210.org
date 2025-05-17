#ifndef PRINTED_CONNECTOR_COMPONENT_H
#define PRINTED_CONNECTOR_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <printed_component.h>

// Unions

// Enumerations

class AP210ARM_API printed_connector_component:
public printed_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 725};

   private:
      // Required attributes

      // Optional attributes

   protected:
      printed_connector_component();

   public:
      ~printed_connector_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_connector_component *InstanceOf(ARMObject *);
      static printed_connector_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_connector_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
