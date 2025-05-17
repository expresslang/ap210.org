#ifndef CONDUCTIVE_INTERCONNECT_ELEMENT_H
#define CONDUCTIVE_INTERCONNECT_ELEMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <laminate_component.h>

// Unions

// Enumerations

class AP210ARM_API conductive_interconnect_element:
public laminate_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 364};

   private:
      // Required attributes
      class stratum_feature *_composed_conductor;

      // Optional attributes

   protected:
      conductive_interconnect_element();

   public:
      ~conductive_interconnect_element();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static conductive_interconnect_element *InstanceOf(ARMObject *);
      static conductive_interconnect_element *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static conductive_interconnect_element *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
