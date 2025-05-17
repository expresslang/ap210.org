#ifndef LEAD_FORM_SPECIFICATION_H
#define LEAD_FORM_SPECIFICATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <process_specification.h>

// Unions

// Enumerations

class AP210ARM_API lead_form_specification:
public process_specification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 632};

   private:
      // Required attributes

      // Optional attributes

   protected:
      lead_form_specification();

   public:
      ~lead_form_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static lead_form_specification *InstanceOf(ARMObject *);
      static lead_form_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static lead_form_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
