#ifndef PHYSICAL_CONNECTIVITY_ABSTRACTION_MAP_H
#define PHYSICAL_CONNECTIVITY_ABSTRACTION_MAP_H

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

class AP210ARM_API physical_connectivity_abstraction_map:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 690};

   private:
      // Required attributes
      class physical_connectivity_element *_name_space_context_based_definition;
      class conductive_interconnect_element *_geometric_context_based_definition;

      // Optional attributes

   protected:
      physical_connectivity_abstraction_map();

   public:
      ~physical_connectivity_abstraction_map();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_connectivity_abstraction_map *InstanceOf(ARMObject *);
      static physical_connectivity_abstraction_map *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_connectivity_abstraction_map *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
