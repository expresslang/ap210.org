#ifndef PHYSICAL_NETWORK_SUPPORTING_STRATUM_FEATURE_CONDUCTIVE_JOIN_H
#define PHYSICAL_NETWORK_SUPPORTING_STRATUM_FEATURE_CONDUCTIVE_JOIN_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <stratum_feature_conductive_join.h>
#include <inter_stratum_join_implementation.h>

// Unions

// Enumerations

class AP210ARM_API physical_network_supporting_stratum_feature_conductive_join:
public stratum_feature_conductive_join,
public inter_stratum_join_implementation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 699};

   private:
      // Required attributes

      // Optional attributes

   protected:
      physical_network_supporting_stratum_feature_conductive_join();

   public:
      ~physical_network_supporting_stratum_feature_conductive_join();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_network_supporting_stratum_feature_conductive_join *InstanceOf(ARMObject *);
      static physical_network_supporting_stratum_feature_conductive_join *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_network_supporting_stratum_feature_conductive_join *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
