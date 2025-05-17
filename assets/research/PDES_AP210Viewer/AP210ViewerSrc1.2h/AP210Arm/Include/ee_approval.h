#ifndef EE_APPROVAL_H
#define EE_APPROVAL_H

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

// Enumerations
#include <status.h>

class AP210ARM_API ee_approval:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 10};

   private:
      // Required attributes
      class ee_text *_purpose;
      union person_organization *_authorizer[2000];
      status::status _approval_status;
      union date_or_date_and_time *_signoff_date;

      // Optional attributes

   protected:
      ee_approval();

   public:
      ~ee_approval();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_approval *InstanceOf(ARMObject *);
      static ee_approval *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_approval *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
