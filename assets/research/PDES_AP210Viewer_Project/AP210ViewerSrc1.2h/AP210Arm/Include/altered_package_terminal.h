#ifndef ALTERED_PACKAGE_TERMINAL_H
#define ALTERED_PACKAGE_TERMINAL_H

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

class AP210ARM_API altered_package_terminal:
public package_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 78};

   private:
      // Required attributes
      class package_terminal *_terminal_to_be_altered;

      // Optional attributes

   protected:
      altered_package_terminal();

   public:
      ~altered_package_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static altered_package_terminal *InstanceOf(ARMObject *);
      static altered_package_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static altered_package_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
