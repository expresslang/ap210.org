#ifndef EXTERNALLY_DEFINED_CURVE_FONT_H
#define EXTERNALLY_DEFINED_CURVE_FONT_H

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

class AP210ARM_API externally_defined_curve_font:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 376};

   private:
      // Required attributes

      // Optional attributes

   protected:
      externally_defined_curve_font();

   public:
      ~externally_defined_curve_font();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static externally_defined_curve_font *InstanceOf(ARMObject *);
      static externally_defined_curve_font *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static externally_defined_curve_font *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
