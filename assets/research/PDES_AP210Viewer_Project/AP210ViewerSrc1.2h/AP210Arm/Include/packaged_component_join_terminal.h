#ifndef PACKAGED_COMPONENT_JOIN_TERMINAL_H
#define PACKAGED_COMPONENT_JOIN_TERMINAL_H

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

class AP210ARM_API packaged_component_join_terminal:
public component_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 185};

   private:
      // Required attributes

      // Optional attributes
      class length_data_element *_maximum_wire_terminal_length;
      class length_data_element *_minimum_wire_terminal_length;

   protected:
      packaged_component_join_terminal();

   public:
      ~packaged_component_join_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static packaged_component_join_terminal *InstanceOf(ARMObject *);
      static packaged_component_join_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static packaged_component_join_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
