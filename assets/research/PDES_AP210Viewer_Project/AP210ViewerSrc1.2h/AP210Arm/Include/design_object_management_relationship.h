#ifndef DESIGN_OBJECT_MANAGEMENT_RELATIONSHIP_H
#define DESIGN_OBJECT_MANAGEMENT_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API design_object_management_relationship:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 2};

   private:
      // Required attributes
      class ee_product_definition *_previous_design;
      class ee_product_definition *_current_design;

      // Optional attributes

   protected:
      design_object_management_relationship();

   public:
      ~design_object_management_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static design_object_management_relationship *InstanceOf(ARMObject *);
      static design_object_management_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static design_object_management_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
