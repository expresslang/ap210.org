#ifndef PART_TERMINAL_EXTERNAL_REFERENCE_H
#define PART_TERMINAL_EXTERNAL_REFERENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <physical_unit_or_part_template.h>

// Enumerations

class AP210ARM_API part_terminal_external_reference:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 176};

   private:
      // Required attributes
      union physical_unit_or_part_template *_associated_definition;
      STR _feature_name;
      STR _feature_type;

      // Optional attributes

   protected:
      part_terminal_external_reference();

   public:
      ~part_terminal_external_reference();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_terminal_external_reference *InstanceOf(ARMObject *);
      static part_terminal_external_reference *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_terminal_external_reference *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
