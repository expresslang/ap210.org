#ifndef SETOFPOSITIONAL_BOUNDARY_MEMBER_DEFINITION_H
#define SETOFPOSITIONAL_BOUNDARY_MEMBER_DEFINITION_H

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

class AP210ARM_API SetOfpositional_boundary_member_definition:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 505};

   private:
      // Required attributes
      class positional_boundary_member_definition *_positional_boundary_member_definition;

      // Optional attributes

   protected:
      SetOfpositional_boundary_member_definition();

   public:
      ~SetOfpositional_boundary_member_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfpositional_boundary_member_definition *InstanceOf(ARMObject *);
      static SetOfpositional_boundary_member_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfpositional_boundary_member_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
