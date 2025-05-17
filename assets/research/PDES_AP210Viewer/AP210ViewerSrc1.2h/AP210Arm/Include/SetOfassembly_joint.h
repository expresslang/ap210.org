#ifndef SETOFASSEMBLY_JOINT_H
#define SETOFASSEMBLY_JOINT_H

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

class AP210ARM_API SetOfassembly_joint:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 702};

   private:
      // Required attributes
      class assembly_joint *_assembly_joint;

      // Optional attributes

   protected:
      SetOfassembly_joint();

   public:
      ~SetOfassembly_joint();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfassembly_joint *InstanceOf(ARMObject *);
      static SetOfassembly_joint *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfassembly_joint *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
