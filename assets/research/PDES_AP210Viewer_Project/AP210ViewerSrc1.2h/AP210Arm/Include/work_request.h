#ifndef WORK_REQUEST_H
#define WORK_REQUEST_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <date_or_date_and_time.h>
#include <evaluated_characteristic_or_description.h>

// Enumerations

class AP210ARM_API work_request:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 266};

   private:
      // Required attributes
      class ee_approval *_work_request_approval;
      union person_organization *_request_recipient[2000];
      STR _work_request_id;
      class ee_product_version *_referenced_product[2000];
      union date_or_date_and_time *_request_date;
      class ee_text *_description;
      union evaluated_characteristic_or_description *_reason;
      union person_organization *_initiator[2000];
      STR _status;

      // Optional attributes

   protected:
      work_request();

   public:
      ~work_request();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static work_request *InstanceOf(ARMObject *);
      static work_request *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static work_request *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
