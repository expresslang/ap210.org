#ifndef FROZEN_ASSIGNMENT_H
#define FROZEN_ASSIGNMENT_H

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

class AP210ARM_API frozen_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 554};

   private:
      // Required attributes
      class frozen_design_object *_frozen_item[2000];
      class ee_approval *_assigned_approval;

      // Optional attributes

   protected:
      frozen_assignment();

   public:
      ~frozen_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static frozen_assignment *InstanceOf(ARMObject *);
      static frozen_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static frozen_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
