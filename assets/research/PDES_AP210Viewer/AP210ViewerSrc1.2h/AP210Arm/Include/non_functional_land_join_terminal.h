#ifndef NON_FUNCTIONAL_LAND_JOIN_TERMINAL_H
#define NON_FUNCTIONAL_LAND_JOIN_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <component_terminal.h>

// Unions

// Enumerations

class AP210ARM_API non_functional_land_join_terminal:
public component_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 454};

   private:
      // Required attributes

      // Optional attributes

   protected:
      non_functional_land_join_terminal();

   public:
      ~non_functional_land_join_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static non_functional_land_join_terminal *InstanceOf(ARMObject *);
      static non_functional_land_join_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static non_functional_land_join_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
