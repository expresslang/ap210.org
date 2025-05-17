#ifndef TOPOLOGICAL_JUNCTION_H
#define TOPOLOGICAL_JUNCTION_H

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

class AP210ARM_API topological_junction:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 277};

   private:
      // Required attributes
      class physical_connectivity_structure_definition *_scope;
      STR _name;

      // Optional attributes

   protected:
      topological_junction();

   public:
      ~topological_junction();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static topological_junction *InstanceOf(ARMObject *);
      static topological_junction *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static topological_junction *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
