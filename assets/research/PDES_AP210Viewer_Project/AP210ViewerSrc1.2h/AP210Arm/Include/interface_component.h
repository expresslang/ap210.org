#ifndef INTERFACE_COMPONENT_H
#define INTERFACE_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_component.h>

// Unions

// Enumerations

class AP210ARM_API interface_component:
public assembly_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 603};

   private:
      // Required attributes

      // Optional attributes

   protected:
      interface_component();

   public:
      ~interface_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interface_component *InstanceOf(ARMObject *);
      static interface_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interface_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
