#ifndef BARE_DIE_TERMINAL_H
#define BARE_DIE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <minimally_defined_bare_die_terminal.h>

// Unions

// Enumerations

class AP210ARM_API bare_die_terminal:
public minimally_defined_bare_die_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 218};

   private:
      // Required attributes
      class ee_material *_material;
      class connection_zone *_external_connection_area;

      // Optional attributes

   protected:
      bare_die_terminal();

   public:
      ~bare_die_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static bare_die_terminal *InstanceOf(ARMObject *);
      static bare_die_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static bare_die_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
