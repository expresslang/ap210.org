#ifndef SPECIAL_SYMBOL_LAMINATE_COMPONENT_H
#define SPECIAL_SYMBOL_LAMINATE_COMPONENT_H

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

class AP210ARM_API special_symbol_laminate_component:
public laminate_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 724};

   private:
      // Required attributes
      class stratum_feature *_stratum_feature_implementation;

      // Optional attributes

   protected:
      special_symbol_laminate_component();

   public:
      ~special_symbol_laminate_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static special_symbol_laminate_component *InstanceOf(ARMObject *);
      static special_symbol_laminate_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static special_symbol_laminate_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
