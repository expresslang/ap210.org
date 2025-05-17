#ifndef INTRA_STRATUM_JOIN_RELATIONSHIP_H
#define INTRA_STRATUM_JOIN_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <join_relationship.h>

// Unions

// Enumerations

class AP210ARM_API intra_stratum_join_relationship:
public join_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 379};

   private:
      // Required attributes

      // Optional attributes

   protected:
      intra_stratum_join_relationship();

   public:
      ~intra_stratum_join_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static intra_stratum_join_relationship *InstanceOf(ARMObject *);
      static intra_stratum_join_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static intra_stratum_join_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
