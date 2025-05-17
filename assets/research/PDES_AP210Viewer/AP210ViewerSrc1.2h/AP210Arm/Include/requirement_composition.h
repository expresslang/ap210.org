#ifndef REQUIREMENT_COMPOSITION_H
#define REQUIREMENT_COMPOSITION_H

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

class AP210ARM_API requirement_composition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 749};

   private:
      // Required attributes
      class ee_requirement_occurrence *_element[2000];
      class requirement_group_occurrence *_composition;

      // Optional attributes

   protected:
      requirement_composition();

   public:
      ~requirement_composition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static requirement_composition *InstanceOf(ARMObject *);
      static requirement_composition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static requirement_composition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
