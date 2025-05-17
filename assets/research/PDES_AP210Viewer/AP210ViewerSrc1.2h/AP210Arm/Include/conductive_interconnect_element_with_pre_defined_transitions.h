#ifndef CONDUCTIVE_INTERCONNECT_ELEMENT_WITH_PRE_DEFINED_TRANSITIONS_H
#define CONDUCTIVE_INTERCONNECT_ELEMENT_WITH_PRE_DEFINED_TRANSITIONS_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <conductive_interconnect_element.h>

// Unions

// Enumerations

class AP210ARM_API conductive_interconnect_element_with_pre_defined_transitions:
public conductive_interconnect_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 366};

   private:
      // Required attributes
      class curve *_centreline_shape;
      class layer_connection_point_link *_connected_points[2000];

      // Optional attributes

   protected:
      conductive_interconnect_element_with_pre_defined_transitions();

   public:
      ~conductive_interconnect_element_with_pre_defined_transitions();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static conductive_interconnect_element_with_pre_defined_transitions *InstanceOf(ARMObject *);
      static conductive_interconnect_element_with_pre_defined_transitions *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static conductive_interconnect_element_with_pre_defined_transitions *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
