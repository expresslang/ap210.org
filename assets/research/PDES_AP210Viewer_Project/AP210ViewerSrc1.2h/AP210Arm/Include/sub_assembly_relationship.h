#ifndef SUB_ASSEMBLY_RELATIONSHIP_H
#define SUB_ASSEMBLY_RELATIONSHIP_H

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

class AP210ARM_API sub_assembly_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 190};

   private:
      // Required attributes
      class assembly_component *_related_components[2000];
      class assembly_group_component *_relating_component;

      // Optional attributes

   protected:
      sub_assembly_relationship();

   public:
      ~sub_assembly_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static sub_assembly_relationship *InstanceOf(ARMObject *);
      static sub_assembly_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static sub_assembly_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
