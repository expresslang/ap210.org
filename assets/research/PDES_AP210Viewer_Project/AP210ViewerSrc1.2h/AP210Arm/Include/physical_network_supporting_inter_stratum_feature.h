#ifndef PHYSICAL_NETWORK_SUPPORTING_INTER_STRATUM_FEATURE_H
#define PHYSICAL_NETWORK_SUPPORTING_INTER_STRATUM_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <plated_inter_stratum_feature.h>
#include <inter_stratum_join_implementation.h>

// Unions

// Enumerations

class AP210ARM_API physical_network_supporting_inter_stratum_feature:
public plated_inter_stratum_feature,
public inter_stratum_join_implementation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 698};

   private:
      // Required attributes

      // Optional attributes

   protected:
      physical_network_supporting_inter_stratum_feature();

   public:
      ~physical_network_supporting_inter_stratum_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_network_supporting_inter_stratum_feature *InstanceOf(ARMObject *);
      static physical_network_supporting_inter_stratum_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_network_supporting_inter_stratum_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
