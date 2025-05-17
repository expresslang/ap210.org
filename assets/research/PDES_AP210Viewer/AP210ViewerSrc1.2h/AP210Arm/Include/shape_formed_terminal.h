#ifndef SHAPE_FORMED_TERMINAL_H
#define SHAPE_FORMED_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <altered_package_terminal.h>

// Unions

// Enumerations

class AP210ARM_API shape_formed_terminal:
public altered_package_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 782};

   private:
      // Required attributes
      class lead_form_specification *_terminal_form_specification;

      // Optional attributes

   protected:
      shape_formed_terminal();

   public:
      ~shape_formed_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static shape_formed_terminal *InstanceOf(ARMObject *);
      static shape_formed_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static shape_formed_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
