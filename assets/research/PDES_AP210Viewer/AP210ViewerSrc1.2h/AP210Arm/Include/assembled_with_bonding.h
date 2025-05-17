#ifndef ASSEMBLED_WITH_BONDING_H
#define ASSEMBLED_WITH_BONDING_H

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

class AP210ARM_API assembled_with_bonding:
public assembly_joint
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 157};

   private:
      // Required attributes
      class assembly_bond_definition *_default_bond_definition;

      // Optional attributes

   protected:
      assembled_with_bonding();

   public:
      ~assembled_with_bonding();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembled_with_bonding *InstanceOf(ARMObject *);
      static assembled_with_bonding *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembled_with_bonding *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
