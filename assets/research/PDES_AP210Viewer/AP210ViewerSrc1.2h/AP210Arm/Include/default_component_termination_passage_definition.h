#ifndef DEFAULT_COMPONENT_TERMINATION_PASSAGE_DEFINITION_H
#define DEFAULT_COMPONENT_TERMINATION_PASSAGE_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <passage_technology.h>

// Unions

// Enumerations

class AP210ARM_API default_component_termination_passage_definition:
public passage_technology
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 438};

   private:
      // Required attributes
      class length_data_element *_minimum_allowed_component_terminal_extent;
      class length_data_element *_maximum_allowed_component_terminal_extent;

      // Optional attributes

   protected:
      default_component_termination_passage_definition();

   public:
      ~default_component_termination_passage_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static default_component_termination_passage_definition *InstanceOf(ARMObject *);
      static default_component_termination_passage_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static default_component_termination_passage_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
