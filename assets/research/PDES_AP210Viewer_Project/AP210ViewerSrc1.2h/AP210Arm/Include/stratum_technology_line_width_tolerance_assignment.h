#ifndef STRATUM_TECHNOLOGY_LINE_WIDTH_TOLERANCE_ASSIGNMENT_H
#define STRATUM_TECHNOLOGY_LINE_WIDTH_TOLERANCE_ASSIGNMENT_H

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

class AP210ARM_API stratum_technology_line_width_tolerance_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 816};

   private:
      // Required attributes
      class stratum_technology *_characterized_stratum_technology;
      class line_width_class *_tolerance_line_width_class;
      class length_data_element *_maximum_negative_deviation;
      class length_data_element *_maximum_positive_deviation;
      class interconnect_module *_design_definition;

      // Optional attributes

   protected:
      stratum_technology_line_width_tolerance_assignment();

   public:
      ~stratum_technology_line_width_tolerance_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_technology_line_width_tolerance_assignment *InstanceOf(ARMObject *);
      static stratum_technology_line_width_tolerance_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_technology_line_width_tolerance_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
