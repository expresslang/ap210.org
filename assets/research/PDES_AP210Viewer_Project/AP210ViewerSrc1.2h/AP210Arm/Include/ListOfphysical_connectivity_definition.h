#ifndef LISTOFPHYSICAL_CONNECTIVITY_DEFINITION_H
#define LISTOFPHYSICAL_CONNECTIVITY_DEFINITION_H

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

class AP210ARM_API ListOfphysical_connectivity_definition:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 621};

   private:
      // Required attributes
      class physical_connectivity_definition *_physical_connectivity_definition;

      // Optional attributes

   protected:
      ListOfphysical_connectivity_definition();

   public:
      ~ListOfphysical_connectivity_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ListOfphysical_connectivity_definition *InstanceOf(ARMObject *);
      static ListOfphysical_connectivity_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ListOfphysical_connectivity_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
