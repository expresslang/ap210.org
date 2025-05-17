#ifndef INTERFACED_GROUP_COMPONENT_H
#define INTERFACED_GROUP_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_group_component.h>

// Unions

// Enumerations

class AP210ARM_API interfaced_group_component:
public assembly_group_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 612};

   private:
      // Required attributes
      class interface_component *_group_interface_component[2000];

      // Optional attributes

   protected:
      interfaced_group_component();

   public:
      ~interfaced_group_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interfaced_group_component *InstanceOf(ARMObject *);
      static interfaced_group_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interfaced_group_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
