#ifndef PACKAGED_PART_H
#define PACKAGED_PART_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_unit_usage_view.h>

// Unions
#include <package_or_package_external_reference.h>

// Enumerations

class AP210ARM_API packaged_part:
public physical_unit_usage_view
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 87};

   private:
      // Required attributes
      union package_or_package_external_reference *_used_package;
      class functional_unit_usage_view *_implemented_function;

      // Optional attributes
      class ee_material *_potting_compound;

   protected:
      packaged_part();

   public:
      ~packaged_part();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static packaged_part *InstanceOf(ARMObject *);
      static packaged_part *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static packaged_part *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
