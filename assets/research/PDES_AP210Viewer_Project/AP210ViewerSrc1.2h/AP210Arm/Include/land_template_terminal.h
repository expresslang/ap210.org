#ifndef LAND_TEMPLATE_TERMINAL_H
#define LAND_TEMPLATE_TERMINAL_H

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
#include <land_template_terminal_class.h>

class AP210ARM_API land_template_terminal:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 163};

   private:
      // Required attributes
      class land_physical_template *_associated_definition;
      class connection_zone *_terminal_connection_zone[2000];
      STR _name;
      land_template_terminal_class::land_template_terminal_class _connection_zone_category;

      // Optional attributes

   protected:
      land_template_terminal();

   public:
      ~land_template_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static land_template_terminal *InstanceOf(ARMObject *);
      static land_template_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static land_template_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
