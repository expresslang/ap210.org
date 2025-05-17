#ifndef COMPONENT_GROUP_ASSIGNMENT_H
#define COMPONENT_GROUP_ASSIGNMENT_H

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

class AP210ARM_API component_group_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 307};

   private:
      // Required attributes
      class placement_group *_associated_group;
      class assembly_component *_assigned_component;

      // Optional attributes

   protected:
      component_group_assignment();

   public:
      ~component_group_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_group_assignment *InstanceOf(ARMObject *);
      static component_group_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_group_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
