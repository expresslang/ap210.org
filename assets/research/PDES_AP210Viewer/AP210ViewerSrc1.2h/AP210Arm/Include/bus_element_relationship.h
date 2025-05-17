#ifndef BUS_ELEMENT_RELATIONSHIP_H
#define BUS_ELEMENT_RELATIONSHIP_H

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

class AP210ARM_API bus_element_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 255};

   private:
      // Required attributes
      union bus_structural_definition_or_node *_element[2000];
      class bus_structural_definition *_bus_definition;

      // Optional attributes

   protected:
      bus_element_relationship();

   public:
      ~bus_element_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static bus_element_relationship *InstanceOf(ARMObject *);
      static bus_element_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static bus_element_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
