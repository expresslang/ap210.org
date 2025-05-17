#ifndef INTERCONNECT_MODULE_STRATUM_ASSEMBLY_RELATIONSHIP_H
#define INTERCONNECT_MODULE_STRATUM_ASSEMBLY_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API interconnect_module_stratum_assembly_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 598};

   private:
      // Required attributes
      class interconnect_module *_assembly;
      class stratum *_component;
      STR _reference_designation;

      // Optional attributes

   protected:
      interconnect_module_stratum_assembly_relationship();

   public:
      ~interconnect_module_stratum_assembly_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interconnect_module_stratum_assembly_relationship *InstanceOf(ARMObject *);
      static interconnect_module_stratum_assembly_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interconnect_module_stratum_assembly_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
