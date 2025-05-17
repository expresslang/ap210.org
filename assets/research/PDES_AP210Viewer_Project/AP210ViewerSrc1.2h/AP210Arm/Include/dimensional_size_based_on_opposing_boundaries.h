#ifndef DIMENSIONAL_SIZE_BASED_ON_OPPOSING_BOUNDARIES_H
#define DIMENSIONAL_SIZE_BASED_ON_OPPOSING_BOUNDARIES_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <dimensional_size.h>

// Unions

// Enumerations

class AP210ARM_API dimensional_size_based_on_opposing_boundaries:
public dimensional_size
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 508};

   private:
      // Required attributes
      class shape_element_locating_relationship *_boundary_separation;

      // Optional attributes

   protected:
      dimensional_size_based_on_opposing_boundaries();

   public:
      ~dimensional_size_based_on_opposing_boundaries();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimensional_size_based_on_opposing_boundaries *InstanceOf(ARMObject *);
      static dimensional_size_based_on_opposing_boundaries *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimensional_size_based_on_opposing_boundaries *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
