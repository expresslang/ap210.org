#ifndef ANALYTICAL_REPRESENTATION_H
#define ANALYTICAL_REPRESENTATION_H

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

class AP210ARM_API analytical_representation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 49};

   private:
      // Required attributes
      class parameter_assignment *_model_parameter_assignment[2000];
      class analytical_model *_model_representation;
      STR _analytical_representation_name;

      // Optional attributes

   protected:
      analytical_representation();

   public:
      ~analytical_representation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static analytical_representation *InstanceOf(ARMObject *);
      static analytical_representation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static analytical_representation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
