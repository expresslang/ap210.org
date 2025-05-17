#ifndef PRINTED_COMPONENT_JOIN_TERMINAL_H
#define PRINTED_COMPONENT_JOIN_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <component_terminal.h>

// Unions
#include <stratum_concept.h>

// Enumerations

class AP210ARM_API printed_component_join_terminal:
public component_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 452};

   private:
      // Required attributes
      class connection_zone *_connection;
      union stratum_concept *_stratum_concept_implementation_component;

      // Optional attributes

   protected:
      printed_component_join_terminal();

   public:
      ~printed_component_join_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_component_join_terminal *InstanceOf(ARMObject *);
      static printed_component_join_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_component_join_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
