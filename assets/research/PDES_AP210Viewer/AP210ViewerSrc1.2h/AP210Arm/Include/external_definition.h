#ifndef EXTERNAL_DEFINITION_H
#define EXTERNAL_DEFINITION_H

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

// Enumerations

class AP210ARM_API external_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 21};

   private:
      // Required attributes
      STR _code;
      STR _code_value;
      union standard_or_reference_document *_reference_document;

      // Optional attributes

   protected:
      external_definition();

   public:
      ~external_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static external_definition *InstanceOf(ARMObject *);
      static external_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static external_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
