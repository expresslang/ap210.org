#ifndef STRATUM_FEATURE_H
#define STRATUM_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_feature_or_part_template.h>

// Unions

// Enumerations

class AP210ARM_API stratum_feature:
public physical_feature_or_part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 241};

   private:
      // Required attributes
      class stratum *_resident_stratum;
      RoseBoolean _feature_of_size;

      // Optional attributes

   protected:
      stratum_feature();

   public:
      ~stratum_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_feature *InstanceOf(ARMObject *);
      static stratum_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
