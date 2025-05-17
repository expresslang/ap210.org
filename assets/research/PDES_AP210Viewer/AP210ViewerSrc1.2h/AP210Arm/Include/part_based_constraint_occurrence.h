#ifndef PART_BASED_CONSTRAINT_OCCURRENCE_H
#define PART_BASED_CONSTRAINT_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <constraint_occurrence.h>

// Unions

// Enumerations

class AP210ARM_API part_based_constraint_occurrence:
public constraint_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 675};

   private:
      // Required attributes
      class ee_product *_constraining_part;

      // Optional attributes

   protected:
      part_based_constraint_occurrence();

   public:
      ~part_based_constraint_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_based_constraint_occurrence *InstanceOf(ARMObject *);
      static part_based_constraint_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_based_constraint_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
