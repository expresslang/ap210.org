#ifndef VIA_TEMPLATE_TERMINAL_H
#define VIA_TEMPLATE_TERMINAL_H

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

class AP210ARM_API via_template_terminal:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 177};

   private:
      // Required attributes
      class via_template *_associated_definition;
      class inter_stratum_extent *_disallowed_inter_stratum_extent;
      STR _name;
      class connection_zone *_terminal_connection_zone[2000];

      // Optional attributes

   protected:
      via_template_terminal();

   public:
      ~via_template_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static via_template_terminal *InstanceOf(ARMObject *);
      static via_template_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static via_template_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
