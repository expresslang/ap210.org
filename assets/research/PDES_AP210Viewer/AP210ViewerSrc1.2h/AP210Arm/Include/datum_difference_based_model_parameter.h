#ifndef DATUM_DIFFERENCE_BASED_MODEL_PARAMETER_H
#define DATUM_DIFFERENCE_BASED_MODEL_PARAMETER_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <model_parameter.h>

// Unions

// Enumerations

class AP210ARM_API datum_difference_based_model_parameter:
public model_parameter
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 417};

   private:
      // Required attributes
      class datum_difference *_of_datum_difference;

      // Optional attributes

   protected:
      datum_difference_based_model_parameter();

   public:
      ~datum_difference_based_model_parameter();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_difference_based_model_parameter *InstanceOf(ARMObject *);
      static datum_difference_based_model_parameter *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_difference_based_model_parameter *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
