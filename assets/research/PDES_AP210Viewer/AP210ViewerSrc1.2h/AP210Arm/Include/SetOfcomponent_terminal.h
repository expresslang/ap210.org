#ifndef SETOFCOMPONENT_TERMINAL_H
#define SETOFCOMPONENT_TERMINAL_H

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

class AP210ARM_API SetOfcomponent_terminal:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 280};

   private:
      // Required attributes
      class component_terminal *_component_terminal;

      // Optional attributes

   protected:
      SetOfcomponent_terminal();

   public:
      ~SetOfcomponent_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfcomponent_terminal *InstanceOf(ARMObject *);
      static SetOfcomponent_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfcomponent_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
