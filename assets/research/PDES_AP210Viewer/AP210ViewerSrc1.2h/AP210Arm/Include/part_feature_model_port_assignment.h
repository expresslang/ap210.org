#ifndef PART_FEATURE_MODEL_PORT_ASSIGNMENT_H
#define PART_FEATURE_MODEL_PORT_ASSIGNMENT_H

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

class AP210ARM_API part_feature_model_port_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 679};

   private:
      // Required attributes
      class part_feature *_source;
      class analytical_model_port *_target;

      // Optional attributes

   protected:
      part_feature_model_port_assignment();

   public:
      ~part_feature_model_port_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_feature_model_port_assignment *InstanceOf(ARMObject *);
      static part_feature_model_port_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_feature_model_port_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
