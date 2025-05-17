#ifndef SETOFFABRICATED_FEATURE_SELECT_H
#define SETOFFABRICATED_FEATURE_SELECT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <fabricated_feature_select.h>

// Enumerations

class AP210ARM_API SetOffabricated_feature_select:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 450};

   private:
      // Required attributes
      union fabricated_feature_select *_fabricated_feature_select;

      // Optional attributes

   protected:
      SetOffabricated_feature_select();

   public:
      ~SetOffabricated_feature_select();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOffabricated_feature_select *InstanceOf(ARMObject *);
      static SetOffabricated_feature_select *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOffabricated_feature_select *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
