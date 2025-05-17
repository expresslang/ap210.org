#ifndef SETOFPERSON_ORGANIZATION_H
#define SETOFPERSON_ORGANIZATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <person_organization.h>

// Enumerations

class AP210ARM_API SetOfperson_organization:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 5};

   private:
      // Required attributes
      union person_organization *_person_organization;

      // Optional attributes

   protected:
      SetOfperson_organization();

   public:
      ~SetOfperson_organization();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfperson_organization *InstanceOf(ARMObject *);
      static SetOfperson_organization *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfperson_organization *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
