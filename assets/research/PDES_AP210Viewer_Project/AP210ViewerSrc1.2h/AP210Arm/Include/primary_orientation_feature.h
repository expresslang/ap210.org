#ifndef PRIMARY_ORIENTATION_FEATURE_H
#define PRIMARY_ORIENTATION_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_feature.h>
#include <datum_feature.h>

// Unions

// Enumerations

class AP210ARM_API primary_orientation_feature:
public part_feature,
public datum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 721};

   private:
      // Required attributes

      // Optional attributes
      class package_body_surface *_associated_body_vertical_extent[2000];

   protected:
      primary_orientation_feature();

   public:
      ~primary_orientation_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static primary_orientation_feature *InstanceOf(ARMObject *);
      static primary_orientation_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static primary_orientation_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
