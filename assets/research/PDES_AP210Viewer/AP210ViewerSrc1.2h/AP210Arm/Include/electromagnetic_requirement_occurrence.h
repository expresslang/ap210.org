#ifndef ELECTROMAGNETIC_REQUIREMENT_OCCURRENCE_H
#define ELECTROMAGNETIC_REQUIREMENT_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_requirement_occurrence.h>

// Unions

// Enumerations

class AP210ARM_API electromagnetic_requirement_occurrence:
public ee_requirement_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 533};

   private:
      // Required attributes

      // Optional attributes

   protected:
      electromagnetic_requirement_occurrence();

   public:
      ~electromagnetic_requirement_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static electromagnetic_requirement_occurrence *InstanceOf(ARMObject *);
      static electromagnetic_requirement_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static electromagnetic_requirement_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
