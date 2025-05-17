#ifndef SETOFPOSITIONAL_BOUNDARY_MEMBER_H
#define SETOFPOSITIONAL_BOUNDARY_MEMBER_H

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

class AP210ARM_API SetOfpositional_boundary_member:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 503};

   private:
      // Required attributes
      class positional_boundary_member *_positional_boundary_member;

      // Optional attributes

   protected:
      SetOfpositional_boundary_member();

   public:
      ~SetOfpositional_boundary_member();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfpositional_boundary_member *InstanceOf(ARMObject *);
      static SetOfpositional_boundary_member *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfpositional_boundary_member *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
