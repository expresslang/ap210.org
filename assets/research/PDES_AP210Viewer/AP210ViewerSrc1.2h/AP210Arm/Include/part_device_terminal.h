#ifndef PART_DEVICE_TERMINAL_H
#define PART_DEVICE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API part_device_terminal:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 490};

   private:
      // Required attributes
      class minimally_defined_bare_die_terminal *_used_bare_die_terminal;
      class part_device *_terminated_device;

      // Optional attributes

   protected:
      part_device_terminal();

   public:
      ~part_device_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_device_terminal *InstanceOf(ARMObject *);
      static part_device_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_device_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
