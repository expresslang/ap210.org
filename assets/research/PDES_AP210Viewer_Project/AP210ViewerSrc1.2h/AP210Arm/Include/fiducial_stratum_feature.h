#ifndef FIDUCIAL_STRATUM_FEATURE_H
#define FIDUCIAL_STRATUM_FEATURE_H

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

class AP210ARM_API fiducial_stratum_feature:
public stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 551};

   private:
      // Required attributes

      // Optional attributes

   protected:
      fiducial_stratum_feature();

   public:
      ~fiducial_stratum_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fiducial_stratum_feature *InstanceOf(ARMObject *);
      static fiducial_stratum_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fiducial_stratum_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
