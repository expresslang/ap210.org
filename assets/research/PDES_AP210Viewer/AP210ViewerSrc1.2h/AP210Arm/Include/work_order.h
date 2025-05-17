#ifndef WORK_ORDER_H
#define WORK_ORDER_H

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
#include <date_or_date_and_time.h>

// Enumerations

class AP210ARM_API work_order:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 264};

   private:
      // Required attributes
      class work_request *_referenced_work_request[2000];
      STR _work_order_id;
      class ee_product_version *_resulting_product[2000];
      class ee_approval *_work_order_approval;
      union person_organization *_initiator[2000];
      union date_or_date_and_time *_start_date;
      union date_or_date_and_time *_release_date;

      // Optional attributes
      class ee_text *_analysis_data;
      class ee_text *_additional_data;
      class contract *_authorizing_agreement;

   protected:
      work_order();

   public:
      ~work_order();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static work_order *InstanceOf(ARMObject *);
      static work_order *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static work_order *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
