#ifndef PACKAGED_CONNECTOR_TERMINAL_RELATIONSHIP_H
#define PACKAGED_CONNECTOR_TERMINAL_RELATIONSHIP_H

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

class AP210ARM_API packaged_connector_terminal_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 670};

   private:
      // Required attributes
      class packaged_connector *_connector;
      class packaged_part_join_terminal *_join_terminal;
      class packaged_part_interface_terminal *_interface_terminal;

      // Optional attributes

   protected:
      packaged_connector_terminal_relationship();

   public:
      ~packaged_connector_terminal_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static packaged_connector_terminal_relationship *InstanceOf(ARMObject *);
      static packaged_connector_terminal_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static packaged_connector_terminal_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
