#ifndef PHYSICAL_CONNECTIVITY_DEFINITION_H
#define PHYSICAL_CONNECTIVITY_DEFINITION_H

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

class AP210ARM_API physical_connectivity_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 279};

   private:
      // Required attributes
      class component_terminal *_associated_terminals[2000];
      STR _name;

      // Optional attributes

   protected:
      physical_connectivity_definition();

   public:
      ~physical_connectivity_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_connectivity_definition *InstanceOf(ARMObject *);
      static physical_connectivity_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_connectivity_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
