#ifndef ASSEMBLY_MODULE_USAGE_VIEW_H
#define ASSEMBLY_MODULE_USAGE_VIEW_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_unit_usage_view.h>

// Unions

// Enumerations

class AP210ARM_API assembly_module_usage_view:
public physical_unit_usage_view
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 207};

   private:
      // Required attributes
      class functional_unit_usage_view *_implemented_function;

      // Optional attributes
      class datum_based_length_measure *_maximum_negative_component_height;
      class datum_based_length_measure *_maximum_positive_component_height;

   protected:
      assembly_module_usage_view();

   public:
      ~assembly_module_usage_view();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_module_usage_view *InstanceOf(ARMObject *);
      static assembly_module_usage_view *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_module_usage_view *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
