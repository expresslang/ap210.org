#ifndef PLATED_INTER_STRATUM_FEATURE_H
#define PLATED_INTER_STRATUM_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <inter_stratum_feature.h>

// Unions

// Enumerations

class AP210ARM_API plated_inter_stratum_feature:
public inter_stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 229};

   private:
      // Required attributes

      // Optional attributes

   protected:
      plated_inter_stratum_feature();

   public:
      ~plated_inter_stratum_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static plated_inter_stratum_feature *InstanceOf(ARMObject *);
      static plated_inter_stratum_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static plated_inter_stratum_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
