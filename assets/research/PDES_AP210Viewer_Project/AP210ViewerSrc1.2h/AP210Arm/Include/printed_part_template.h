#ifndef PRINTED_PART_TEMPLATE_H
#define PRINTED_PART_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_template.h>

// Unions

// Enumerations

class AP210ARM_API printed_part_template:
public part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 172};

   private:
      // Required attributes
      class printed_part_template_material *_characterized_material[2000];
      class functional_unit_usage_view *_implemented_function;

      // Optional attributes
      class printed_part_cross_section_template *_cross_section;

   protected:
      printed_part_template();

   public:
      ~printed_part_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_part_template *InstanceOf(ARMObject *);
      static printed_part_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_part_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
