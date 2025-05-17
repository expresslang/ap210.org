#ifndef CONTRACT_H
#define CONTRACT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <person_organization.h>
#include <date_or_date_and_time.h>

// Enumerations

class AP210ARM_API contract:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 15};

   private:
      // Required attributes
      class ee_text *_contract_number;
      class ee_approval *_contract_approval;
      union date_or_date_and_time *_contract_date;

      // Optional attributes
      union person_organization *_contractor;

   protected:
      contract();

   public:
      ~contract();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static contract *InstanceOf(ARMObject *);
      static contract *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static contract *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
