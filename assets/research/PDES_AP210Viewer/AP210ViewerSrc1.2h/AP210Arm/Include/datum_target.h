#ifndef DATUM_TARGET_H
#define DATUM_TARGET_H

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

class AP210ARM_API datum_target:
public physical_feature_or_part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 428};

   private:
      // Required attributes

      // Optional attributes

   protected:
      datum_target();

   public:
      ~datum_target();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_target *InstanceOf(ARMObject *);
      static datum_target *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_target *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
