#ifndef LAYOUT_SPACING_REQUIREMENT_NON_CONFORMING_DESIGN_OBJECT_H
#define LAYOUT_SPACING_REQUIREMENT_NON_CONFORMING_DESIGN_OBJECT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <assembly_or_interconnect_design_object_select.h>

// Enumerations

class AP210ARM_API layout_spacing_requirement_non_conforming_design_object:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 630};

   private:
      // Required attributes
      union assembly_or_interconnect_design_object_select *_non_conformant_design_object[2000];
      union assembly_or_interconnect_design_object_select *_reference_design_object;
      class layout_spacing_requirement_occurrence *_design_requirement;

      // Optional attributes

   protected:
      layout_spacing_requirement_non_conforming_design_object();

   public:
      ~layout_spacing_requirement_non_conforming_design_object();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static layout_spacing_requirement_non_conforming_design_object *InstanceOf(ARMObject *);
      static layout_spacing_requirement_non_conforming_design_object *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static layout_spacing_requirement_non_conforming_design_object *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
