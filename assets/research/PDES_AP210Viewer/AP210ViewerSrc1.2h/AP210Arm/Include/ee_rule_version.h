#ifndef EE_RULE_VERSION_H
#define EE_RULE_VERSION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <document_or_organization.h>

// Enumerations

class AP210ARM_API ee_rule_version:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 397};

   private:
      // Required attributes
      class ee_rule *_configuration_managed_rule;
      STR _version_identifier;

      // Optional attributes
      union document_or_organization *_source;

   protected:
      ee_rule_version();

   public:
      ~ee_rule_version();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_rule_version *InstanceOf(ARMObject *);
      static ee_rule_version *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_rule_version *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
