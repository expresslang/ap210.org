#ifndef CONNECTIVITY_SUB_STRUCTURE_H
#define CONNECTIVITY_SUB_STRUCTURE_H

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

class AP210ARM_API connectivity_sub_structure:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 275};

   private:
      // Required attributes
      union termination_or_junction *_members[2000];

      // Optional attributes

   protected:
      connectivity_sub_structure();

   public:
      ~connectivity_sub_structure();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static connectivity_sub_structure *InstanceOf(ARMObject *);
      static connectivity_sub_structure *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static connectivity_sub_structure *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
