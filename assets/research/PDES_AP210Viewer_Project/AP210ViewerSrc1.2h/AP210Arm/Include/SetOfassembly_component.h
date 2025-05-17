#ifndef SETOFASSEMBLY_COMPONENT_H
#define SETOFASSEMBLY_COMPONENT_H

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

class AP210ARM_API SetOfassembly_component:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 191};

   private:
      // Required attributes
      class assembly_component *_assembly_component;

      // Optional attributes

   protected:
      SetOfassembly_component();

   public:
      ~SetOfassembly_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfassembly_component *InstanceOf(ARMObject *);
      static SetOfassembly_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfassembly_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
