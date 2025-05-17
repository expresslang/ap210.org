#ifndef PHYSICAL_CONNECTIVITY_STRUCTURE_DEFINITION_H
#define PHYSICAL_CONNECTIVITY_STRUCTURE_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_connectivity_definition.h>

// Unions

// Enumerations

class AP210ARM_API physical_connectivity_structure_definition:
public physical_connectivity_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 278};

   private:
      // Required attributes

      // Optional attributes

   protected:
      physical_connectivity_structure_definition();

   public:
      ~physical_connectivity_structure_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_connectivity_structure_definition *InstanceOf(ARMObject *);
      static physical_connectivity_structure_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_connectivity_structure_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
