#ifndef PURPOSE_OCCURRENCE_H
#define PURPOSE_OCCURRENCE_H

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

class AP210ARM_API purpose_occurrence:
public ee_requirement_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 745};

   private:
      // Required attributes

      // Optional attributes

   protected:
      purpose_occurrence();

   public:
      ~purpose_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static purpose_occurrence *InstanceOf(ARMObject *);
      static purpose_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static purpose_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
