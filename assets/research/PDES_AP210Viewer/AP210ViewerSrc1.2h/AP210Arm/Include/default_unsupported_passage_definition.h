#ifndef DEFAULT_UNSUPPORTED_PASSAGE_DEFINITION_H
#define DEFAULT_UNSUPPORTED_PASSAGE_DEFINITION_H

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

class AP210ARM_API default_unsupported_passage_definition:
public passage_technology
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 441};

   private:
      // Required attributes

      // Optional attributes

   protected:
      default_unsupported_passage_definition();

   public:
      ~default_unsupported_passage_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static default_unsupported_passage_definition *InstanceOf(ARMObject *);
      static default_unsupported_passage_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static default_unsupported_passage_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
