#ifndef PACKAGE_TERMINAL_OCCURRENCE_H
#define PACKAGE_TERMINAL_OCCURRENCE_H

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

class AP210ARM_API package_terminal_occurrence:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 182};

   private:
      // Required attributes
      class package_terminal *_definition;
      class packaged_component *_associated_component;

      // Optional attributes

   protected:
      package_terminal_occurrence();

   public:
      ~package_terminal_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static package_terminal_occurrence *InstanceOf(ARMObject *);
      static package_terminal_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static package_terminal_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
