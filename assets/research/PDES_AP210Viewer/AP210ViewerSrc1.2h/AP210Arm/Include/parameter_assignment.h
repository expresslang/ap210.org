#ifndef PARAMETER_ASSIGNMENT_H
#define PARAMETER_ASSIGNMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <scalar_or_coordinated_characteristics.h>

// Enumerations

class AP210ARM_API parameter_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 51};

   private:
      // Required attributes
      union scalar_or_coordinated_characteristics *_parameter_value;
      class model_parameter *_assigned_parameter;

      // Optional attributes

   protected:
      parameter_assignment();

   public:
      ~parameter_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static parameter_assignment *InstanceOf(ARMObject *);
      static parameter_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static parameter_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
