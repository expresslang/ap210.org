#ifndef BONDED_CONDUCTIVE_BASE_BLIND_VIA_H
#define BONDED_CONDUCTIVE_BASE_BLIND_VIA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <blind_via.h>

// Unions

// Enumerations

class AP210ARM_API bonded_conductive_base_blind_via:
public blind_via
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 237};

   private:
      // Required attributes
      class stratum_feature_conductive_join *_features_join;

      // Optional attributes

   protected:
      bonded_conductive_base_blind_via();

   public:
      ~bonded_conductive_base_blind_via();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static bonded_conductive_base_blind_via *InstanceOf(ARMObject *);
      static bonded_conductive_base_blind_via *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static bonded_conductive_base_blind_via *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
