#ifndef PHYSICAL_CONNECTIVITY_INTERRUPTING_CUTOUT_H
#define PHYSICAL_CONNECTIVITY_INTERRUPTING_CUTOUT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <cutout.h>

// Unions

// Enumerations

class AP210ARM_API physical_connectivity_interrupting_cutout:
public cutout
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 692};

   private:
      // Required attributes
      class conductive_interconnect_element *_interrupted_connectivity_element[2000];

      // Optional attributes

   protected:
      physical_connectivity_interrupting_cutout();

   public:
      ~physical_connectivity_interrupting_cutout();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_connectivity_interrupting_cutout *InstanceOf(ARMObject *);
      static physical_connectivity_interrupting_cutout *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_connectivity_interrupting_cutout *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
