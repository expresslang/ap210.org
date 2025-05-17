#ifndef SETOFDESIGN_INTENT_MODIFICATION_PLANAR_SHAPE_H
#define SETOFDESIGN_INTENT_MODIFICATION_PLANAR_SHAPE_H

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

class AP210ARM_API SetOfdesign_intent_modification_planar_shape:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 463};

   private:
      // Required attributes
      class design_intent_modification_planar_shape *_design_intent_modification_planar_shape;

      // Optional attributes

   protected:
      SetOfdesign_intent_modification_planar_shape();

   public:
      ~SetOfdesign_intent_modification_planar_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfdesign_intent_modification_planar_shape *InstanceOf(ARMObject *);
      static SetOfdesign_intent_modification_planar_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfdesign_intent_modification_planar_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
