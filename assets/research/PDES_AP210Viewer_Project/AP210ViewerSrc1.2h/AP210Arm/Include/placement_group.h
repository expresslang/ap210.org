#ifndef PLACEMENT_GROUP_H
#define PLACEMENT_GROUP_H

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

class AP210ARM_API placement_group:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 308};

   private:
      // Required attributes
      STR _design_specific_usage;
      class ee_requirement_occurrence *_requirement[2000];

      // Optional attributes

   protected:
      placement_group();

   public:
      ~placement_group();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static placement_group *InstanceOf(ARMObject *);
      static placement_group *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static placement_group *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
