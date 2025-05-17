#ifndef EE_DOCUMENT_IDENTIFIER_H
#define EE_DOCUMENT_IDENTIFIER_H

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

class AP210ARM_API ee_document_identifier:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 22};

   private:
      // Required attributes
      STR _identifier_name;
      STR _assigned_value;

      // Optional attributes

   protected:
      ee_document_identifier();

   public:
      ~ee_document_identifier();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_document_identifier *InstanceOf(ARMObject *);
      static ee_document_identifier *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_document_identifier *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
