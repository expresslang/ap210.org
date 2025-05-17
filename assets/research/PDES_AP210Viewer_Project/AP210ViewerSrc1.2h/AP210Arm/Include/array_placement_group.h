#ifndef ARRAY_PLACEMENT_GROUP_H
#define ARRAY_PLACEMENT_GROUP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_group_component.h>

// Unions

// Enumerations

class AP210ARM_API array_placement_group:
public assembly_group_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 151};

   private:
      // Required attributes

      // Optional attributes

   protected:
      array_placement_group();

   public:
      ~array_placement_group();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static array_placement_group *InstanceOf(ARMObject *);
      static array_placement_group *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static array_placement_group *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
