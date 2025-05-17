#ifndef SECURITY_CLASSIFICATION_H
#define SECURITY_CLASSIFICATION_H

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

class AP210ARM_API security_classification:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 9};

   private:
      // Required attributes
      class person *_classification_officer;
      class ee_approval *_security_classification_approval;
      union date_or_date_and_time *_classification_date;

      // Optional attributes
      union date_or_date_and_time *_declassification_date;

   protected:
      security_classification();

   public:
      ~security_classification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static security_classification *InstanceOf(ARMObject *);
      static security_classification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static security_classification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
