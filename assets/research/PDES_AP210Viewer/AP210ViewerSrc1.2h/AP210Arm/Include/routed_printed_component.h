#ifndef ROUTED_PRINTED_COMPONENT_H
#define ROUTED_PRINTED_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <laminate_component.h>

// Unions

// Enumerations

class AP210ARM_API routed_printed_component:
public laminate_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 755};

   private:
      // Required attributes
      class feature_shape_definition *_routed_shape;
      class inter_stratum_extent *_component_extent;

      // Optional attributes

   protected:
      routed_printed_component();

   public:
      ~routed_printed_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static routed_printed_component *InstanceOf(ARMObject *);
      static routed_printed_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static routed_printed_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
