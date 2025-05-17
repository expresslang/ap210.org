#ifndef EE_SPECIFICATION_H
#define EE_SPECIFICATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_document.h>

// Unions
#include <person_organization.h>

// Enumerations

class AP210ARM_API ee_specification:
public ee_document
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 38};

   private:
      // Required attributes
      union person_organization *_source;

      // Optional attributes
      STR _code_or_identifier;

   protected:
      ee_specification();

   public:
      ~ee_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_specification *InstanceOf(ARMObject *);
      static ee_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
