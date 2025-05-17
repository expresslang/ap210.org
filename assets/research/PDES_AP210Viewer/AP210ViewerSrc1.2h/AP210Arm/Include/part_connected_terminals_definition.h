#ifndef PART_CONNECTED_TERMINALS_DEFINITION_H
#define PART_CONNECTED_TERMINALS_DEFINITION_H

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

class AP210ARM_API part_connected_terminals_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 676};

   private:
      // Required attributes
      class part_terminal *_connected_terminals[2000];
      STR _name;

      // Optional attributes

   protected:
      part_connected_terminals_definition();

   public:
      ~part_connected_terminals_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_connected_terminals_definition *InstanceOf(ARMObject *);
      static part_connected_terminals_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_connected_terminals_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
