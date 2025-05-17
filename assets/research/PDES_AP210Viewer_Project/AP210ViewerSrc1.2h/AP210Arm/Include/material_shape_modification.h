#ifndef MATERIAL_SHAPE_MODIFICATION_H
#define MATERIAL_SHAPE_MODIFICATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <design_intent_modification.h>

// Unions

// Enumerations

class AP210ARM_API material_shape_modification:
public design_intent_modification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 649};

   private:
      // Required attributes

      // Optional attributes

   protected:
      material_shape_modification();

   public:
      ~material_shape_modification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static material_shape_modification *InstanceOf(ARMObject *);
      static material_shape_modification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static material_shape_modification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
