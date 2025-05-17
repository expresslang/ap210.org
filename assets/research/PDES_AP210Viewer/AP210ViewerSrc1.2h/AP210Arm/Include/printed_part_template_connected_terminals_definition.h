#ifndef PRINTED_PART_TEMPLATE_CONNECTED_TERMINALS_DEFINITION_H
#define PRINTED_PART_TEMPLATE_CONNECTED_TERMINALS_DEFINITION_H

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

class AP210ARM_API printed_part_template_connected_terminals_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 730};

   private:
      // Required attributes
      class printed_part_template_terminal *_connected_terminals[2000];
      STR _name;

      // Optional attributes

   protected:
      printed_part_template_connected_terminals_definition();

   public:
      ~printed_part_template_connected_terminals_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_part_template_connected_terminals_definition *InstanceOf(ARMObject *);
      static printed_part_template_connected_terminals_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_part_template_connected_terminals_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
