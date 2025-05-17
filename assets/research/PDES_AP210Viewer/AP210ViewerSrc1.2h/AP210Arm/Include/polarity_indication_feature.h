#ifndef POLARITY_INDICATION_FEATURE_H
#define POLARITY_INDICATION_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_feature.h>

// Unions

// Enumerations

class AP210ARM_API polarity_indication_feature:
public part_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 716};

   private:
      // Required attributes
      class package_terminal *_associated_terminal;

      // Optional attributes
      class package_body_surface *_associated_body_vertical_extent[2000];

   protected:
      polarity_indication_feature();

   public:
      ~polarity_indication_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static polarity_indication_feature *InstanceOf(ARMObject *);
      static polarity_indication_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static polarity_indication_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
