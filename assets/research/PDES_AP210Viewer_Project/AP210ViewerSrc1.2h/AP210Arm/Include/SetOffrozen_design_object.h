#ifndef SETOFFROZEN_DESIGN_OBJECT_H
#define SETOFFROZEN_DESIGN_OBJECT_H

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

class AP210ARM_API SetOffrozen_design_object:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 555};

   private:
      // Required attributes
      class frozen_design_object *_frozen_design_object;

      // Optional attributes

   protected:
      SetOffrozen_design_object();

   public:
      ~SetOffrozen_design_object();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOffrozen_design_object *InstanceOf(ARMObject *);
      static SetOffrozen_design_object *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOffrozen_design_object *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
