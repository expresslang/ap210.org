#ifndef PHYSICAL_LAMINATE_COMPONENT_H
#define PHYSICAL_LAMINATE_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <laminate_component.h>
#include <physical_feature_or_part_template.h>

// Unions

// Enumerations

class AP210ARM_API physical_laminate_component:
public laminate_component,
public physical_feature_or_part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 695};

   private:
      // Required attributes

      // Optional attributes

   protected:
      physical_laminate_component();

   public:
      ~physical_laminate_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_laminate_component *InstanceOf(ARMObject *);
      static physical_laminate_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_laminate_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
