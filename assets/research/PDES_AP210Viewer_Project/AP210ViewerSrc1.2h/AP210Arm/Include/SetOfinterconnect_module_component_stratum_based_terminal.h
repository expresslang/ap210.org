#ifndef SETOFINTERCONNECT_MODULE_COMPONENT_STRATUM_BASED_TERMINAL_H
#define SETOFINTERCONNECT_MODULE_COMPONENT_STRATUM_BASED_TERMINAL_H

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

class AP210ARM_API SetOfinterconnect_module_component_stratum_based_terminal:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 596};

   private:
      // Required attributes
      class interconnect_module_component_stratum_based_terminal *_interconnect_module_component_stratum_based_terminal;

      // Optional attributes

   protected:
      SetOfinterconnect_module_component_stratum_based_terminal();

   public:
      ~SetOfinterconnect_module_component_stratum_based_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfinterconnect_module_component_stratum_based_terminal *InstanceOf(ARMObject *);
      static SetOfinterconnect_module_component_stratum_based_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfinterconnect_module_component_stratum_based_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
