#ifndef PHYSICAL_FEATURE_OR_PART_TEMPLATE_H
#define PHYSICAL_FEATURE_OR_PART_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <shape_element.h>

// Unions

// Enumerations

class AP210ARM_API physical_feature_or_part_template:
public shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 81};

   private:
      // Required attributes

      // Optional attributes

   protected:
      physical_feature_or_part_template();

   public:
      ~physical_feature_or_part_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_feature_or_part_template *InstanceOf(ARMObject *);
      static physical_feature_or_part_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_feature_or_part_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
