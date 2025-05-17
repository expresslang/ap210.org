#ifndef INTERFACE_REQUIREMENT_OCCURRENCE_H
#define INTERFACE_REQUIREMENT_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <design_requirement_occurrence.h>

// Unions

// Enumerations

class AP210ARM_API interface_requirement_occurrence:
public design_requirement_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 609};

   private:
      // Required attributes
      class next_higher_assembly_interface_requirement *_interface_to_next_higher_assembly;

      // Optional attributes

   protected:
      interface_requirement_occurrence();

   public:
      ~interface_requirement_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interface_requirement_occurrence *InstanceOf(ARMObject *);
      static interface_requirement_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interface_requirement_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
