#ifndef PRINTED_COMPONENT_H
#define PRINTED_COMPONENT_H

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

class AP210ARM_API printed_component:
public laminate_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 619};

   private:
      // Required attributes
      class stratum_feature *_stratum_feature_implementation[2000];

      // Optional attributes

   protected:
      printed_component();

   public:
      ~printed_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_component *InstanceOf(ARMObject *);
      static printed_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
