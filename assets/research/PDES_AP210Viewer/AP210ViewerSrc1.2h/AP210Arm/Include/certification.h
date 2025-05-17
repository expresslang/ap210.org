#ifndef CERTIFICATION_H
#define CERTIFICATION_H

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

class AP210ARM_API certification:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 260};

   private:
      // Required attributes
      class ee_approval *_certification_approval;
      class ee_text *_certification_number;
      class supplied_product_version *_certified_product_version;
      union date_or_date_and_time *_certification_date;

      // Optional attributes

   protected:
      certification();

   public:
      ~certification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static certification *InstanceOf(ARMObject *);
      static certification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static certification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
