#ifndef FUNCTIONAL_SPECIFICATION_H
#define FUNCTIONAL_SPECIFICATION_H

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

class AP210ARM_API functional_specification:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 557};

   private:
      // Required attributes
      class signal_specification *_reference_signal;
      class signal_specification *_characterizing_signal;
      class external_definition *_characteristic_category;

      // Optional attributes

   protected:
      functional_specification();

   public:
      ~functional_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_specification *InstanceOf(ARMObject *);
      static functional_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
