#ifndef DEFAULT_VIA_DEFINITION_H
#define DEFAULT_VIA_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <passage_technology.h>

// Unions

// Enumerations

class AP210ARM_API default_via_definition:
public passage_technology
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 442};

   private:
      // Required attributes

      // Optional attributes

   protected:
      default_via_definition();

   public:
      ~default_via_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static default_via_definition *InstanceOf(ARMObject *);
      static default_via_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static default_via_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
