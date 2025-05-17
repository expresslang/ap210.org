#ifndef ROUTED_PACKAGED_COMPONENT_H
#define ROUTED_PACKAGED_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <packaged_component.h>

// Unions

// Enumerations

class AP210ARM_API routed_packaged_component:
public packaged_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 754};

   private:
      // Required attributes
      class feature_shape_definition *_routed_shape;

      // Optional attributes

   protected:
      routed_packaged_component();

   public:
      ~routed_packaged_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static routed_packaged_component *InstanceOf(ARMObject *);
      static routed_packaged_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static routed_packaged_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
