#ifndef CONDUCTIVE_INTERCONNECT_ELEMENT_WITH_USER_DEFINED_SINGLE_TRANSITION_H
#define CONDUCTIVE_INTERCONNECT_ELEMENT_WITH_USER_DEFINED_SINGLE_TRANSITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <conductive_interconnect_element.h>

// Unions
#include <trimmed_or_bounding_curve.h>
#include <trimmed_or_bounding_curve.h>

// Enumerations

class AP210ARM_API conductive_interconnect_element_with_user_defined_single_transition:
public conductive_interconnect_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 371};

   private:
      // Required attributes
      class trace_template *_start_definition;
      class trace_template *_end_definition;
      union trimmed_or_bounding_curve *_left_curve_shape_representation;
      union trimmed_or_bounding_curve *_right_curve_shape_representation;
      class layer_connection_point *_start_terminus;
      class layer_connection_point *_end_terminus;

      // Optional attributes

   protected:
      conductive_interconnect_element_with_user_defined_single_transition();

   public:
      ~conductive_interconnect_element_with_user_defined_single_transition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static conductive_interconnect_element_with_user_defined_single_transition *InstanceOf(ARMObject *);
      static conductive_interconnect_element_with_user_defined_single_transition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static conductive_interconnect_element_with_user_defined_single_transition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
