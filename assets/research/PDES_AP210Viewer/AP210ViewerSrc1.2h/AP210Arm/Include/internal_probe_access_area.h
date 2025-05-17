#ifndef INTERNAL_PROBE_ACCESS_AREA_H
#define INTERNAL_PROBE_ACCESS_AREA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <probe_access_area.h>

// Unions

// Enumerations

class AP210ARM_API internal_probe_access_area:
public probe_access_area
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 615};

   private:
      // Required attributes
      class stratum_feature *_stratum_feature_implementation;

      // Optional attributes

   protected:
      internal_probe_access_area();

   public:
      ~internal_probe_access_area();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static internal_probe_access_area *InstanceOf(ARMObject *);
      static internal_probe_access_area *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static internal_probe_access_area *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
