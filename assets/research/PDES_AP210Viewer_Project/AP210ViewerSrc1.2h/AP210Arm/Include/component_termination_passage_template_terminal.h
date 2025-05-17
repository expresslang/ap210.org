#ifndef COMPONENT_TERMINATION_PASSAGE_TEMPLATE_TERMINAL_H
#define COMPONENT_TERMINATION_PASSAGE_TEMPLATE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API component_termination_passage_template_terminal:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 166};

   private:
      // Required attributes
      class component_termination_passage_template *_associated_definition;
      class connection_zone *_terminal_connection_zone[2000];
      STR _name;

      // Optional attributes

   protected:
      component_termination_passage_template_terminal();

   public:
      ~component_termination_passage_template_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_termination_passage_template_terminal *InstanceOf(ARMObject *);
      static component_termination_passage_template_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_termination_passage_template_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
