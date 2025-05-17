#ifndef ASSEMBLY_MODULE_COMPONENT_TERMINAL_H
#define ASSEMBLY_MODULE_COMPONENT_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <component_terminal.h>

// Unions

// Enumerations

class AP210ARM_API assembly_module_component_terminal:
public component_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 186};

   private:
      // Required attributes

      // Optional attributes

   protected:
      assembly_module_component_terminal();

   public:
      ~assembly_module_component_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_module_component_terminal *InstanceOf(ARMObject *);
      static assembly_module_component_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_module_component_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
