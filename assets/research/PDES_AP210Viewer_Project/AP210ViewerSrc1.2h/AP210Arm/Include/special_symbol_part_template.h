#ifndef SPECIAL_SYMBOL_PART_TEMPLATE_H
#define SPECIAL_SYMBOL_PART_TEMPLATE_H

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

class AP210ARM_API special_symbol_part_template:
public part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 790};

   private:
      // Required attributes

      // Optional attributes

   protected:
      special_symbol_part_template();

   public:
      ~special_symbol_part_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static special_symbol_part_template *InstanceOf(ARMObject *);
      static special_symbol_part_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static special_symbol_part_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
