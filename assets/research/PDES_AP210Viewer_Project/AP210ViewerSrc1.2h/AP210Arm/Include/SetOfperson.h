#ifndef SETOFPERSON_H
#define SETOFPERSON_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfperson:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 25};

   private:
      // Required attributes
      class person *_person;

      // Optional attributes

   protected:
      SetOfperson();

   public:
      ~SetOfperson();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfperson *InstanceOf(ARMObject *);
      static SetOfperson *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfperson *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
