#ifndef PACKAGED_CONNECTOR_COMPONENT_H
#define PACKAGED_CONNECTOR_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <packaged_component.h>

// Unions

// Enumerations

class AP210ARM_API packaged_connector_component:
public packaged_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 669};

   private:
      // Required attributes

      // Optional attributes

   protected:
      packaged_connector_component();

   public:
      ~packaged_connector_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static packaged_connector_component *InstanceOf(ARMObject *);
      static packaged_connector_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static packaged_connector_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
