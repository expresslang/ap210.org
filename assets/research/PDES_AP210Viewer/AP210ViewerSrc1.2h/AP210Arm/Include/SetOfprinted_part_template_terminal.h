#ifndef SETOFPRINTED_PART_TEMPLATE_TERMINAL_H
#define SETOFPRINTED_PART_TEMPLATE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfprinted_part_template_terminal:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 731};

   private:
      // Required attributes
      class printed_part_template_terminal *_printed_part_template_terminal;

      // Optional attributes

   protected:
      SetOfprinted_part_template_terminal();

   public:
      ~SetOfprinted_part_template_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfprinted_part_template_terminal *InstanceOf(ARMObject *);
      static SetOfprinted_part_template_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfprinted_part_template_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
