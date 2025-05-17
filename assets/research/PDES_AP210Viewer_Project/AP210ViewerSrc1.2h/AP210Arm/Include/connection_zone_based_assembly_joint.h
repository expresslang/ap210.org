#ifndef CONNECTION_ZONE_BASED_ASSEMBLY_JOINT_H
#define CONNECTION_ZONE_BASED_ASSEMBLY_JOINT_H

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

class AP210ARM_API connection_zone_based_assembly_joint:
public assembly_joint
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 387};

   private:
      // Required attributes
      class connection_zone *_zone_1;
      class connection_zone *_zone_2;

      // Optional attributes

   protected:
      connection_zone_based_assembly_joint();

   public:
      ~connection_zone_based_assembly_joint();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static connection_zone_based_assembly_joint *InstanceOf(ARMObject *);
      static connection_zone_based_assembly_joint *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static connection_zone_based_assembly_joint *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
