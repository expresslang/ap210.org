#ifndef CONDUCTOR_H
#define CONDUCTOR_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <stratum_feature.h>

// Unions

// Enumerations

class AP210ARM_API conductor:
public stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 378};

   private:
      // Required attributes
      class intra_stratum_join_relationship *_implementation_requirement;

      // Optional attributes

   protected:
      conductor();

   public:
      ~conductor();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static conductor *InstanceOf(ARMObject *);
      static conductor *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static conductor *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
