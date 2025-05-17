#ifndef TRUE_PROFILE_H
#define TRUE_PROFILE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <true_profile_representations.h>

// Enumerations

class AP210ARM_API true_profile:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 735};

   private:
      // Required attributes
      class physical_feature_or_part_template *_profiled_surface;
      union true_profile_representations *_profile_representation;

      // Optional attributes

   protected:
      true_profile();

   public:
      ~true_profile();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static true_profile *InstanceOf(ARMObject *);
      static true_profile *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static true_profile *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
