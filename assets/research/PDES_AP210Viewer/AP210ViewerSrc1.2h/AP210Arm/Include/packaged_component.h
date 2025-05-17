#ifndef PACKAGED_COMPONENT_H
#define PACKAGED_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_component.h>

// Unions

// Enumerations

class AP210ARM_API packaged_component:
public assembly_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 183};

   private:
      // Required attributes

      // Optional attributes
      class altered_package *_selected_package_alternate;

   protected:
      packaged_component();

   public:
      ~packaged_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static packaged_component *InstanceOf(ARMObject *);
      static packaged_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static packaged_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
