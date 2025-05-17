#ifndef SETOFPART_FEATURE_H
#define SETOFPART_FEATURE_H

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

class AP210ARM_API SetOfpart_feature:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 546};

   private:
      // Required attributes
      class part_feature *_part_feature;

      // Optional attributes

   protected:
      SetOfpart_feature();

   public:
      ~SetOfpart_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfpart_feature *InstanceOf(ARMObject *);
      static SetOfpart_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfpart_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
