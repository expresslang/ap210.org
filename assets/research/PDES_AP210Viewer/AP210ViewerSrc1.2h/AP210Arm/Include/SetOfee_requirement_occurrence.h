#ifndef SETOFEE_REQUIREMENT_OCCURRENCE_H
#define SETOFEE_REQUIREMENT_OCCURRENCE_H

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

class AP210ARM_API SetOfee_requirement_occurrence:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 65};

   private:
      // Required attributes
      class ee_requirement_occurrence *_ee_requirement_occurrence;

      // Optional attributes

   protected:
      SetOfee_requirement_occurrence();

   public:
      ~SetOfee_requirement_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfee_requirement_occurrence *InstanceOf(ARMObject *);
      static SetOfee_requirement_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfee_requirement_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
