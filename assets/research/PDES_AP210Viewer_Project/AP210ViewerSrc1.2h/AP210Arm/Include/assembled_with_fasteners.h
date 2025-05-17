#ifndef ASSEMBLED_WITH_FASTENERS_H
#define ASSEMBLED_WITH_FASTENERS_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_joint.h>

// Unions

// Enumerations

class AP210ARM_API assembled_with_fasteners:
public assembly_joint
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 189};

   private:
      // Required attributes
      class sub_assembly_relationship *_sub_assembly;

      // Optional attributes

   protected:
      assembled_with_fasteners();

   public:
      ~assembled_with_fasteners();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembled_with_fasteners *InstanceOf(ARMObject *);
      static assembled_with_fasteners *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembled_with_fasteners *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
