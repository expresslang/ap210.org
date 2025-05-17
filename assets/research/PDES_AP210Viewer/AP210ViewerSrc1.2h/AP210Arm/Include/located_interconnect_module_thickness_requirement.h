#ifndef LOCATED_INTERCONNECT_MODULE_THICKNESS_REQUIREMENT_H
#define LOCATED_INTERCONNECT_MODULE_THICKNESS_REQUIREMENT_H

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

class AP210ARM_API located_interconnect_module_thickness_requirement:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 602};

   private:
      // Required attributes
      class axis_placement *_reference_location;
      class length_data_element *_maximum_thickness_requirement;
      class length_data_element *_minimum_thickness_requirement;

      // Optional attributes

   protected:
      located_interconnect_module_thickness_requirement();

   public:
      ~located_interconnect_module_thickness_requirement();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static located_interconnect_module_thickness_requirement *InstanceOf(ARMObject *);
      static located_interconnect_module_thickness_requirement *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static located_interconnect_module_thickness_requirement *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
