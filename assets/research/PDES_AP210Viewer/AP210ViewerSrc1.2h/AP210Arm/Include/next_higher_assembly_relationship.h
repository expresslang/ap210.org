#ifndef NEXT_HIGHER_ASSEMBLY_RELATIONSHIP_H
#define NEXT_HIGHER_ASSEMBLY_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_composition_relationship.h>

// Unions

// Enumerations

class AP210ARM_API next_higher_assembly_relationship:
public assembly_composition_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 299};

   private:
      // Required attributes
      STR _reference_designation;

      // Optional attributes
      class data_element *_quantity;

   protected:
      next_higher_assembly_relationship();

   public:
      ~next_higher_assembly_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static next_higher_assembly_relationship *InstanceOf(ARMObject *);
      static next_higher_assembly_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static next_higher_assembly_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
