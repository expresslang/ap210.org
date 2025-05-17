#ifndef ITEM_RESTRICTED_REQUIREMENT_OCCURRENCE_H
#define ITEM_RESTRICTED_REQUIREMENT_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_requirement_occurrence.h>

// Unions
#include <restriction_basis_item.h>

// Enumerations

class AP210ARM_API item_restricted_requirement_occurrence:
public ee_requirement_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 321};

   private:
      // Required attributes
      union restriction_basis_item *_basis;

      // Optional attributes

   protected:
      item_restricted_requirement_occurrence();

   public:
      ~item_restricted_requirement_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static item_restricted_requirement_occurrence *InstanceOf(ARMObject *);
      static item_restricted_requirement_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static item_restricted_requirement_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
