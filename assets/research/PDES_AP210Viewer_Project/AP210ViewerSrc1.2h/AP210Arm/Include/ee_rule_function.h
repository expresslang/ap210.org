#ifndef EE_RULE_FUNCTION_H
#define EE_RULE_FUNCTION_H

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

class AP210ARM_API ee_rule_function:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 521};

   private:
      // Required attributes
      STR _identifier;
      class model_parameter *_parameter[2000];
      class ee_document *_reference_document;
      class ee_specification *_source_code;

      // Optional attributes

   protected:
      ee_rule_function();

   public:
      ~ee_rule_function();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_rule_function *InstanceOf(ARMObject *);
      static ee_rule_function *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_rule_function *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
