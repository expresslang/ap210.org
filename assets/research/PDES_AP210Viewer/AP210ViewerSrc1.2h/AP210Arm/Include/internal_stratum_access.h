#ifndef INTERNAL_STRATUM_ACCESS_H
#define INTERNAL_STRATUM_ACCESS_H

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

class AP210ARM_API internal_stratum_access:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 617};

   private:
      // Required attributes
      class internal_probe_access_area *_connected_probe;
      class via *_inter_stratum_feature;

      // Optional attributes

   protected:
      internal_stratum_access();

   public:
      ~internal_stratum_access();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static internal_stratum_access *InstanceOf(ARMObject *);
      static internal_stratum_access *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static internal_stratum_access *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
