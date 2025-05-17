#ifndef MINIMALLY_DEFINED_BARE_DIE_TERMINAL_H
#define MINIMALLY_DEFINED_BARE_DIE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_terminal.h>

// Unions

// Enumerations

class AP210ARM_API minimally_defined_bare_die_terminal:
public part_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 219};

   private:
      // Required attributes

      // Optional attributes

   protected:
      minimally_defined_bare_die_terminal();

   public:
      ~minimally_defined_bare_die_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static minimally_defined_bare_die_terminal *InstanceOf(ARMObject *);
      static minimally_defined_bare_die_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static minimally_defined_bare_die_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
