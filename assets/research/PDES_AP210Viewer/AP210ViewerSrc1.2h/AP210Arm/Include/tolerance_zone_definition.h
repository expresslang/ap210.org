#ifndef TOLERANCE_ZONE_DEFINITION_H
#define TOLERANCE_ZONE_DEFINITION_H

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

class AP210ARM_API tolerance_zone_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 116};

   private:
      // Required attributes
      class tolerance_zone *_defined_tolerance_zone;
      class tolerance_zone_boundary_definition *_boundary_definition;

      // Optional attributes
      class tolerance_zone_form *_form;

   protected:
      tolerance_zone_definition();

   public:
      ~tolerance_zone_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone_definition *InstanceOf(ARMObject *);
      static tolerance_zone_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
