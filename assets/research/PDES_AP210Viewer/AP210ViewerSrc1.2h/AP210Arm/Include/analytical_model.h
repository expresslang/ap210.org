#ifndef ANALYTICAL_MODEL_H
#define ANALYTICAL_MODEL_H

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

class AP210ARM_API analytical_model:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 53};

   private:
      // Required attributes
      STR _name;
      class language_reference_manual *_representation_language;
      class ee_document *_reference_document;
      class model_parameter *_parameter[2000];
      class ee_specification *_source_code;

      // Optional attributes

   protected:
      analytical_model();

   public:
      ~analytical_model();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static analytical_model *InstanceOf(ARMObject *);
      static analytical_model *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static analytical_model *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
