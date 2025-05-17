#ifndef COMPONENT_TERMINATION_PASSAGE_DEPENDENT_LAND_H
#define COMPONENT_TERMINATION_PASSAGE_DEPENDENT_LAND_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <land.h>

// Unions

// Enumerations

class AP210ARM_API component_termination_passage_dependent_land:
public land
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 337};

   private:
      // Required attributes
      class component_termination_passage *_reference_passage;

      // Optional attributes

   protected:
      component_termination_passage_dependent_land();

   public:
      ~component_termination_passage_dependent_land();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_termination_passage_dependent_land *InstanceOf(ARMObject *);
      static component_termination_passage_dependent_land *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_termination_passage_dependent_land *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
