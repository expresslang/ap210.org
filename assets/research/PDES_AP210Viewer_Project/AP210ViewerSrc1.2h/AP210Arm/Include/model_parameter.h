#ifndef MODEL_PARAMETER_H
#define MODEL_PARAMETER_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <standard_or_reference_document.h>
#include <scalar_or_coordinated_characteristics.h>

// Enumerations
#include <model_parameter_type.h>

class AP210ARM_API model_parameter:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 52};

   private:
      // Required attributes
      STR _type_name;
      union standard_or_reference_document *_reference_document;
      model_parameter_type::model_parameter_type _parameter_type;

      // Optional attributes
      STR _unit_of_measure;
      class coordinated_characteristic *_valid_range[2000];
      union scalar_or_coordinated_characteristics *_default_value;

   protected:
      model_parameter();

   public:
      ~model_parameter();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static model_parameter *InstanceOf(ARMObject *);
      static model_parameter *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static model_parameter *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
