#ifndef EE_REQUIREMENT_OCCURRENCE_H
#define EE_REQUIREMENT_OCCURRENCE_H

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

class AP210ARM_API ee_requirement_occurrence:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 66};

   private:
      // Required attributes
      class ee_specification *_requirement_specification[2000];
      STR _name;

      // Optional attributes
      class analytical_representation *_required_analytical_representation[2000];
      class ee_specification *_required_specification[2000];
      class ee_product *_required_part[2000];
      class coordinated_characteristic *_required_coordinated_characteristic[2000];
      class characteristic *_required_characteristic[2000];
      class ee_material *_required_material;
      class ee_text *_description;

   protected:
      ee_requirement_occurrence();

   public:
      ~ee_requirement_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_requirement_occurrence *InstanceOf(ARMObject *);
      static ee_requirement_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_requirement_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
