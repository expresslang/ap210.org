#ifndef PRINTED_PART_TEMPLATE_TERMINAL_RELATIONSHIP_H
#define PRINTED_PART_TEMPLATE_TERMINAL_RELATIONSHIP_H

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

class AP210ARM_API printed_part_template_terminal_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 732};

   private:
      // Required attributes
      class printed_part_template_terminal *_related_printed_part_terminal;
      class printed_part_template_terminal *_relating_printed_part_terminal;

      // Optional attributes

   protected:
      printed_part_template_terminal_relationship();

   public:
      ~printed_part_template_terminal_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_part_template_terminal_relationship *InstanceOf(ARMObject *);
      static printed_part_template_terminal_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_part_template_terminal_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
