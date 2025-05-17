#ifndef PHYSICAL_CONNECTIVITY_ELEMENT_H
#define PHYSICAL_CONNECTIVITY_ELEMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <connectivity_component.h>
#include <connectivity_component.h>

// Enumerations

class AP210ARM_API physical_connectivity_element:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 274};

   private:
      // Required attributes
      union connectivity_component *_start_terminus;
      STR _name;
      union connectivity_component *_end_terminus;
      class physical_connectivity_structure_definition *_connectivity_context;

      // Optional attributes

   protected:
      physical_connectivity_element();

   public:
      ~physical_connectivity_element();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_connectivity_element *InstanceOf(ARMObject *);
      static physical_connectivity_element *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_connectivity_element *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
