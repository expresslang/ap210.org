#ifndef JOIN_TWO_PHYSICAL_CONNECTIVITY_DEFINITION_SUPPORTING_PRINTED_COMPONENT_H
#define JOIN_TWO_PHYSICAL_CONNECTIVITY_DEFINITION_SUPPORTING_PRINTED_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <printed_component.h>

// Unions

// Enumerations

class AP210ARM_API join_two_physical_connectivity_definition_supporting_printed_component:
public printed_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 618};

   private:
      // Required attributes
      class physical_connectivity_definition *_joined_definitions[2000];

      // Optional attributes

   protected:
      join_two_physical_connectivity_definition_supporting_printed_component();

   public:
      ~join_two_physical_connectivity_definition_supporting_printed_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static join_two_physical_connectivity_definition_supporting_printed_component *InstanceOf(ARMObject *);
      static join_two_physical_connectivity_definition_supporting_printed_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static join_two_physical_connectivity_definition_supporting_printed_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
