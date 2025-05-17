#ifndef SETOFSTRATUM_FEATURE_H
#define SETOFSTRATUM_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfstratum_feature:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 620};

   private:
      // Required attributes
      class stratum_feature *_stratum_feature;

      // Optional attributes

   protected:
      SetOfstratum_feature();

   public:
      ~SetOfstratum_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfstratum_feature *InstanceOf(ARMObject *);
      static SetOfstratum_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfstratum_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
