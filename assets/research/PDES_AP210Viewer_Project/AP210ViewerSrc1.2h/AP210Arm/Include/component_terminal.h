#ifndef COMPONENT_TERMINAL_H
#define COMPONENT_TERMINAL_H

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

class AP210ARM_API component_terminal:
public component_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 161};

   private:
      // Required attributes

      // Optional attributes
      RoseBoolean _local_swappable;
      RoseBoolean _global_swappable;
      STR _swap_code;

   protected:
      component_terminal();

   public:
      ~component_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_terminal *InstanceOf(ARMObject *);
      static component_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
