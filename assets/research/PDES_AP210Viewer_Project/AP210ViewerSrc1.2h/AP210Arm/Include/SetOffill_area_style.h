#ifndef SETOFFILL_AREA_STYLE_H
#define SETOFFILL_AREA_STYLE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOffill_area_style:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 466};

   private:
      // Required attributes
      class fill_area_style *_fill_area_style;

      // Optional attributes

   protected:
      SetOffill_area_style();

   public:
      ~SetOffill_area_style();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOffill_area_style *InstanceOf(ARMObject *);
      static SetOffill_area_style *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOffill_area_style *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
