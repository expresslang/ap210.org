#ifndef PHYSICAL_UNIT_RELATIONSHIP_H
#define PHYSICAL_UNIT_RELATIONSHIP_H

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

class AP210ARM_API physical_unit_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 703};

   private:
      // Required attributes
      class physical_unit *_relating_unit;
      class physical_unit *_related_unit;

      // Optional attributes

   protected:
      physical_unit_relationship();

   public:
      ~physical_unit_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_unit_relationship *InstanceOf(ARMObject *);
      static physical_unit_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_unit_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
