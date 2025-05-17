#ifndef FUNCTIONAL_TERMINAL_GROUP_H
#define FUNCTIONAL_TERMINAL_GROUP_H

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

class AP210ARM_API functional_terminal_group:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 561};

   private:
      // Required attributes
      STR _name;
      STR _group_description;
      STR _group_type;

      // Optional attributes

   protected:
      functional_terminal_group();

   public:
      ~functional_terminal_group();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_terminal_group *InstanceOf(ARMObject *);
      static functional_terminal_group *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_terminal_group *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
