#ifndef TOLERANCE_ZONE_FORM_H
#define TOLERANCE_ZONE_FORM_H

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

class AP210ARM_API tolerance_zone_form:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 120};

   private:
      // Required attributes
      class tolerance_zone *_characterized_tolerance_zone;
      STR _name;

      // Optional attributes

   protected:
      tolerance_zone_form();

   public:
      ~tolerance_zone_form();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone_form *InstanceOf(ARMObject *);
      static tolerance_zone_form *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone_form *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
