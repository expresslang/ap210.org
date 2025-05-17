#ifndef PLACEMENT_GROUP_AREA_ASSIGNMENT_H
#define PLACEMENT_GROUP_AREA_ASSIGNMENT_H

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

class AP210ARM_API placement_group_area_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 704};

   private:
      // Required attributes
      class placement_group *_placed_group;
      class mounting_restriction_area *_area;

      // Optional attributes

   protected:
      placement_group_area_assignment();

   public:
      ~placement_group_area_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static placement_group_area_assignment *InstanceOf(ARMObject *);
      static placement_group_area_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static placement_group_area_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
