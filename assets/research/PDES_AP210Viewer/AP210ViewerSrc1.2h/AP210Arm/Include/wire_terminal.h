#ifndef WIRE_TERMINAL_H
#define WIRE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <package_terminal.h>

// Unions

// Enumerations

class AP210ARM_API wire_terminal:
public package_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 861};

   private:
      // Required attributes
      class length_data_element *_maximum_wire_terminal_length;
      class length_data_element *_minimum_wire_terminal_length;

      // Optional attributes

   protected:
      wire_terminal();

   public:
      ~wire_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static wire_terminal *InstanceOf(ARMObject *);
      static wire_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static wire_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
