#ifndef SURFACE_PREPPED_TERMINAL_H
#define SURFACE_PREPPED_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <altered_package_terminal.h>

// Unions

// Enumerations

class AP210ARM_API surface_prepped_terminal:
public altered_package_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 819};

   private:
      // Required attributes
      class surface_finish_specification *_surface_preparation;

      // Optional attributes

   protected:
      surface_prepped_terminal();

   public:
      ~surface_prepped_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static surface_prepped_terminal *InstanceOf(ARMObject *);
      static surface_prepped_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static surface_prepped_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
