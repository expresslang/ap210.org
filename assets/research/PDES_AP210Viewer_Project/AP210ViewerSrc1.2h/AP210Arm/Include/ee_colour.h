#ifndef EE_COLOUR_H
#define EE_COLOUR_H

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

class AP210ARM_API ee_colour:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 84};

   private:
      // Required attributes
      STR _name;

      // Optional attributes

   protected:
      ee_colour();

   public:
      ~ee_colour();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_colour *InstanceOf(ARMObject *);
      static ee_colour *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_colour *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
