#ifndef ASSEMBLY_GROUP_COMPONENT_H
#define ASSEMBLY_GROUP_COMPONENT_H

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

class AP210ARM_API assembly_group_component:
public assembly_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 152};

   private:
      // Required attributes

      // Optional attributes

   protected:
      assembly_group_component();

   public:
      ~assembly_group_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_group_component *InstanceOf(ARMObject *);
      static assembly_group_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_group_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
