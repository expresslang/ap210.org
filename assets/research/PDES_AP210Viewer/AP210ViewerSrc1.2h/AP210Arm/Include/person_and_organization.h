#ifndef PERSON_AND_ORGANIZATION_H
#define PERSON_AND_ORGANIZATION_H

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

class AP210ARM_API person_and_organization:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 6};

   private:
      // Required attributes
      class person *_assigned_person;
      class organization *_assigned_organization;

      // Optional attributes

   protected:
      person_and_organization();

   public:
      ~person_and_organization();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static person_and_organization *InstanceOf(ARMObject *);
      static person_and_organization *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static person_and_organization *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
