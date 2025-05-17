#ifndef LAMINATE_COMPONENT_H
#define LAMINATE_COMPONENT_H

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

class AP210ARM_API laminate_component:
public assembly_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 231};

   private:
      // Required attributes

      // Optional attributes
      class external_definition *_cad_layer;

   protected:
      laminate_component();

   public:
      ~laminate_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static laminate_component *InstanceOf(ARMObject *);
      static laminate_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static laminate_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
