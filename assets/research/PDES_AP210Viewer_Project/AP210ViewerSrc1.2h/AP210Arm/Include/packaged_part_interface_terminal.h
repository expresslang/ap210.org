#ifndef PACKAGED_PART_INTERFACE_TERMINAL_H
#define PACKAGED_PART_INTERFACE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <packaged_part_terminal.h>

// Unions

// Enumerations

class AP210ARM_API packaged_part_interface_terminal:
public packaged_part_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 202};

   private:
      // Required attributes

      // Optional attributes

   protected:
      packaged_part_interface_terminal();

   public:
      ~packaged_part_interface_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static packaged_part_interface_terminal *InstanceOf(ARMObject *);
      static packaged_part_interface_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static packaged_part_interface_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
