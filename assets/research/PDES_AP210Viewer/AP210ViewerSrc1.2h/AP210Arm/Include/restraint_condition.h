#ifndef RESTRAINT_CONDITION_H
#define RESTRAINT_CONDITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <restrained_item_select.h>

// Enumerations

class AP210ARM_API restraint_condition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 601};

   private:
      // Required attributes
      class ee_requirement_occurrence *_restraint_description;
      union restrained_item_select *_applied_to;

      // Optional attributes

   protected:
      restraint_condition();

   public:
      ~restraint_condition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static restraint_condition *InstanceOf(ARMObject *);
      static restraint_condition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static restraint_condition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
