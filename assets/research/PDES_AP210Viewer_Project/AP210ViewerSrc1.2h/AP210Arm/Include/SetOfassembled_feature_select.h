#ifndef SETOFASSEMBLED_FEATURE_SELECT_H
#define SETOFASSEMBLED_FEATURE_SELECT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <assembled_feature_select.h>

// Enumerations

class AP210ARM_API SetOfassembled_feature_select:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 159};

   private:
      // Required attributes
      union assembled_feature_select *_assembled_feature_select;

      // Optional attributes

   protected:
      SetOfassembled_feature_select();

   public:
      ~SetOfassembled_feature_select();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfassembled_feature_select *InstanceOf(ARMObject *);
      static SetOfassembled_feature_select *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfassembled_feature_select *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
