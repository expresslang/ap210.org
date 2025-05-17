#ifndef REFERENCE_COMPOSITION_PATH_H
#define REFERENCE_COMPOSITION_PATH_H

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

class AP210ARM_API reference_composition_path:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 456};

   private:
      // Required attributes
      class functional_unit *_path_element[2000];
      class functional_unit *_reference_functional_unit;

      // Optional attributes

   protected:
      reference_composition_path();

   public:
      ~reference_composition_path();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static reference_composition_path *InstanceOf(ARMObject *);
      static reference_composition_path *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static reference_composition_path *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
