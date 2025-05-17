#ifndef SETOFDESIGN_OBJECT_MANAGEMENT_RELATIONSHIP_OR_DESCRIPTION_H
#define SETOFDESIGN_OBJECT_MANAGEMENT_RELATIONSHIP_OR_DESCRIPTION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <design_object_management_relationship_or_description.h>

// Enumerations

class AP210ARM_API SetOfdesign_object_management_relationship_or_description:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 285};

   private:
      // Required attributes
      union design_object_management_relationship_or_description *_design_object_management_relationship_or_description;

      // Optional attributes

   protected:
      SetOfdesign_object_management_relationship_or_description();

   public:
      ~SetOfdesign_object_management_relationship_or_description();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfdesign_object_management_relationship_or_description *InstanceOf(ARMObject *);
      static SetOfdesign_object_management_relationship_or_description *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfdesign_object_management_relationship_or_description *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
