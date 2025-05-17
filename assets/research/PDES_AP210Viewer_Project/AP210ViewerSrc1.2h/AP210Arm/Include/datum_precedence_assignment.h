#ifndef DATUM_PRECEDENCE_ASSIGNMENT_H
#define DATUM_PRECEDENCE_ASSIGNMENT_H

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
#include <precedence_type.h>

class AP210ARM_API datum_precedence_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 148};

   private:
      // Required attributes
      class datum_usage_in_datum_system_relationship *_assigned_to;
      precedence_type::precedence_type _name;

      // Optional attributes

   protected:
      datum_precedence_assignment();

   public:
      ~datum_precedence_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_precedence_assignment *InstanceOf(ARMObject *);
      static datum_precedence_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_precedence_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
