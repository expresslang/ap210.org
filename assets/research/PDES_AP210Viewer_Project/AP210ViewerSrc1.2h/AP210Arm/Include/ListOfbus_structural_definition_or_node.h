#ifndef LISTOFBUS_STRUCTURAL_DEFINITION_OR_NODE_H
#define LISTOFBUS_STRUCTURAL_DEFINITION_OR_NODE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <bus_structural_definition_or_node.h>

// Enumerations

class AP210ARM_API ListOfbus_structural_definition_or_node:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 256};

   private:
      // Required attributes
      union bus_structural_definition_or_node *_bus_structural_definition_or_node;

      // Optional attributes

   protected:
      ListOfbus_structural_definition_or_node();

   public:
      ~ListOfbus_structural_definition_or_node();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ListOfbus_structural_definition_or_node *InstanceOf(ARMObject *);
      static ListOfbus_structural_definition_or_node *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ListOfbus_structural_definition_or_node *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
