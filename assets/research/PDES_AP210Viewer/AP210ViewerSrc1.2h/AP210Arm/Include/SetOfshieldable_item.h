#ifndef SETOFSHIELDABLE_ITEM_H
#define SETOFSHIELDABLE_ITEM_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <shieldable_item.h>

// Enumerations

class AP210ARM_API SetOfshieldable_item:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 786};

   private:
      // Required attributes
      union shieldable_item *_shieldable_item;

      // Optional attributes

   protected:
      SetOfshieldable_item();

   public:
      ~SetOfshieldable_item();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfshieldable_item *InstanceOf(ARMObject *);
      static SetOfshieldable_item *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfshieldable_item *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
