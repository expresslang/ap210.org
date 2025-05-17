#ifndef COMPOSITE_SIGNAL_PROPERTY_RELATIONSHIP_H
#define COMPOSITE_SIGNAL_PROPERTY_RELATIONSHIP_H

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

class AP210ARM_API composite_signal_property_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 358};

   private:
      // Required attributes
      class composite_signal_property *_composition;
      class signal_property *_signal_property_structural_element;
      class external_definition *_aggregation_operation;

      // Optional attributes

   protected:
      composite_signal_property_relationship();

   public:
      ~composite_signal_property_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static composite_signal_property_relationship *InstanceOf(ARMObject *);
      static composite_signal_property_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static composite_signal_property_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
