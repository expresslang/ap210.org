#ifndef SHIELD_H
#define SHIELD_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_component.h>

// Unions

// Enumerations

class AP210ARM_API shield:
public assembly_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 785};

   private:
      // Required attributes
      union shieldable_item *_shielded_item[2000];

      // Optional attributes

   protected:
      shield();

   public:
      ~shield();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static shield *InstanceOf(ARMObject *);
      static shield *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static shield *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
