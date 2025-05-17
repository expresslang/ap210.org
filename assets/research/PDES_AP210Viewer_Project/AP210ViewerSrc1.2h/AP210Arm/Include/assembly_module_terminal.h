#ifndef ASSEMBLY_MODULE_TERMINAL_H
#define ASSEMBLY_MODULE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_terminal.h>

// Unions

// Enumerations

class AP210ARM_API assembly_module_terminal:
public part_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 200};

   private:
      // Required attributes

      // Optional attributes
      class packaged_part_interface_terminal *_reference_terminal;
      class assembly_module_usage_view_connector_relationship *_related_connector;
      class connection_zone *_terminal_connection_zone[2000];

   protected:
      assembly_module_terminal();

   public:
      ~assembly_module_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_module_terminal *InstanceOf(ARMObject *);
      static assembly_module_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_module_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
