#ifndef INTER_STRATUM_FEATURE_H
#define INTER_STRATUM_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <laminate_component.h>
#include <physical_feature_or_part_template.h>

// Unions

// Enumerations

class AP210ARM_API inter_stratum_feature:
public laminate_component,
public physical_feature_or_part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 230};

   private:
      // Required attributes
      RoseBoolean _feature_of_size;

      // Optional attributes

   protected:
      inter_stratum_feature();

   public:
      ~inter_stratum_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static inter_stratum_feature *InstanceOf(ARMObject *);
      static inter_stratum_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static inter_stratum_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
