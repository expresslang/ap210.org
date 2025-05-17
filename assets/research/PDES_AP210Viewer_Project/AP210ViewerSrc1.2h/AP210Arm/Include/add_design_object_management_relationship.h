#ifndef ADD_DESIGN_OBJECT_MANAGEMENT_RELATIONSHIP_H
#define ADD_DESIGN_OBJECT_MANAGEMENT_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <design_object_management_relationship.h>

// Unions

// Enumerations

class AP210ARM_API add_design_object_management_relationship:
public design_object_management_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 1};

   private:
      // Required attributes
      class managed_design_object *_current_design_object;

      // Optional attributes

   protected:
      add_design_object_management_relationship();

   public:
      ~add_design_object_management_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static add_design_object_management_relationship *InstanceOf(ARMObject *);
      static add_design_object_management_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static add_design_object_management_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
