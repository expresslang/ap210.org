#ifndef PRINTED_PART_TEMPLATE_TERMINAL_H
#define PRINTED_PART_TEMPLATE_TERMINAL_H

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
#include <printed_part_template_terminal_class.h>

class AP210ARM_API printed_part_template_terminal:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 171};

   private:
      // Required attributes
      class feature_shape_occurrence *_feature_shape[2000];
      class printed_part_template *_associated_definition;
      printed_part_template_terminal_class::printed_part_template_terminal_class _connection_zone_category;
      class connection_zone *_terminal_connection_zone[2000];
      STR _name;

      // Optional attributes

   protected:
      printed_part_template_terminal();

   public:
      ~printed_part_template_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_part_template_terminal *InstanceOf(ARMObject *);
      static printed_part_template_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_part_template_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
