#ifndef PART_ARRAY_FEATURE_H
#define PART_ARRAY_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_group_feature.h>

// Unions

// Enumerations

class AP210ARM_API part_array_feature:
public part_group_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 674};

   private:
      // Required attributes

      // Optional attributes

   protected:
      part_array_feature();

   public:
      ~part_array_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_array_feature *InstanceOf(ARMObject *);
      static part_array_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_array_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
