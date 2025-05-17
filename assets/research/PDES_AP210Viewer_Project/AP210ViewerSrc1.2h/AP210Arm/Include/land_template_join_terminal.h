#ifndef LAND_TEMPLATE_JOIN_TERMINAL_H
#define LAND_TEMPLATE_JOIN_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <land_template_terminal.h>

// Unions

// Enumerations

class AP210ARM_API land_template_join_terminal:
public land_template_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 626};

   private:
      // Required attributes

      // Optional attributes

   protected:
      land_template_join_terminal();

   public:
      ~land_template_join_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static land_template_join_terminal *InstanceOf(ARMObject *);
      static land_template_join_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static land_template_join_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
