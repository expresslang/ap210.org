#ifndef TRACE_TEMPLATE_H
#define TRACE_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_template.h>

// Unions

// Enumerations

class AP210ARM_API trace_template:
public part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 372};

   private:
      // Required attributes
      class curve_style *_trace_style;

      // Optional attributes

   protected:
      trace_template();

   public:
      ~trace_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static trace_template *InstanceOf(ARMObject *);
      static trace_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static trace_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
