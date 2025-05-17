#ifndef DEFAULT_TRACE_TEMPLATE_H
#define DEFAULT_TRACE_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <trace_template.h>

// Unions

// Enumerations

class AP210ARM_API default_trace_template:
public trace_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 439};

   private:
      // Required attributes
      class stratum_technology *_of_stratum_technology;

      // Optional attributes

   protected:
      default_trace_template();

   public:
      ~default_trace_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static default_trace_template *InstanceOf(ARMObject *);
      static default_trace_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static default_trace_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
