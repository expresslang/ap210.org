#ifndef ASSEMBLY_REQUIREMENT_ALLOCATION_H
#define ASSEMBLY_REQUIREMENT_ALLOCATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <component_or_feature.h>

// Enumerations

class AP210ARM_API assembly_requirement_allocation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 209};

   private:
      // Required attributes
      union component_or_feature *_assembly_assignment;
      class ee_requirement_occurrence *_requirement;

      // Optional attributes

   protected:
      assembly_requirement_allocation();

   public:
      ~assembly_requirement_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_requirement_allocation *InstanceOf(ARMObject *);
      static assembly_requirement_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_requirement_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
