#ifndef PRIMARY_REFERENCE_TERMINAL_H
#define PRIMARY_REFERENCE_TERMINAL_H

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

class AP210ARM_API primary_reference_terminal:
public package_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 722};

   private:
      // Required attributes

      // Optional attributes

   protected:
      primary_reference_terminal();

   public:
      ~primary_reference_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static primary_reference_terminal *InstanceOf(ARMObject *);
      static primary_reference_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static primary_reference_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
