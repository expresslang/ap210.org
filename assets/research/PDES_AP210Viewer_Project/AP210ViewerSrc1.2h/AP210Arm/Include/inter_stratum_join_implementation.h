#ifndef INTER_STRATUM_JOIN_IMPLEMENTATION_H
#define INTER_STRATUM_JOIN_IMPLEMENTATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API inter_stratum_join_implementation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 581};

   private:
      // Required attributes
      class inter_stratum_join_relationship *_topological_requirement;

      // Optional attributes

   protected:
      inter_stratum_join_implementation();

   public:
      ~inter_stratum_join_implementation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static inter_stratum_join_implementation *InstanceOf(ARMObject *);
      static inter_stratum_join_implementation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static inter_stratum_join_implementation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
