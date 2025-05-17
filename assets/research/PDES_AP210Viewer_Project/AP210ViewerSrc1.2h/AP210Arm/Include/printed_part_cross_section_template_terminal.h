#ifndef PRINTED_PART_CROSS_SECTION_TEMPLATE_TERMINAL_H
#define PRINTED_PART_CROSS_SECTION_TEMPLATE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <printed_part_template_terminal.h>

// Unions

// Enumerations

class AP210ARM_API printed_part_cross_section_template_terminal:
public printed_part_template_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 729};

   private:
      // Required attributes

      // Optional attributes

   protected:
      printed_part_cross_section_template_terminal();

   public:
      ~printed_part_cross_section_template_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_part_cross_section_template_terminal *InstanceOf(ARMObject *);
      static printed_part_cross_section_template_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_part_cross_section_template_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
