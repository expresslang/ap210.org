#ifndef TOLERANCE_ZONE_DEFINITION_WITH_SPECIFIED_ORIENTATION_H
#define TOLERANCE_ZONE_DEFINITION_WITH_SPECIFIED_ORIENTATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <tolerance_zone_definition.h>

// Unions
#include <orientation_select.h>

// Enumerations

class AP210ARM_API tolerance_zone_definition_with_specified_orientation:
public tolerance_zone_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 843};

   private:
      // Required attributes
      union orientation_select *_zone_orientation;

      // Optional attributes

   protected:
      tolerance_zone_definition_with_specified_orientation();

   public:
      ~tolerance_zone_definition_with_specified_orientation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone_definition_with_specified_orientation *InstanceOf(ARMObject *);
      static tolerance_zone_definition_with_specified_orientation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone_definition_with_specified_orientation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
