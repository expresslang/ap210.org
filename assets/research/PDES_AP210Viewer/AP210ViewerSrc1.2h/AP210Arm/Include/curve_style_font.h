#ifndef CURVE_STYLE_FONT_H
#define CURVE_STYLE_FONT_H

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

class AP210ARM_API curve_style_font:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 377};

   private:
      // Required attributes

      // Optional attributes

   protected:
      curve_style_font();

   public:
      ~curve_style_font();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static curve_style_font *InstanceOf(ARMObject *);
      static curve_style_font *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static curve_style_font *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
