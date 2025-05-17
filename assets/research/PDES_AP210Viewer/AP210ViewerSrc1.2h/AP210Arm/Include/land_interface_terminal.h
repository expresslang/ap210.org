#ifndef LAND_INTERFACE_TERMINAL_H
#define LAND_INTERFACE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <component_feature.h>

// Unions

// Enumerations

class AP210ARM_API land_interface_terminal:
public component_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 329};

   private:
      // Required attributes

      // Optional attributes

   protected:
      land_interface_terminal();

   public:
      ~land_interface_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static land_interface_terminal *InstanceOf(ARMObject *);
      static land_interface_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static land_interface_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
