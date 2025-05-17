#ifndef LINE_WIDTH_CLASS_H
#define LINE_WIDTH_CLASS_H

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

class AP210ARM_API line_width_class:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 637};

   private:
      // Required attributes
      class curve_style *_class_member[2000];
      STR _class_name;

      // Optional attributes

   protected:
      line_width_class();

   public:
      ~line_width_class();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static line_width_class *InstanceOf(ARMObject *);
      static line_width_class *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static line_width_class *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
