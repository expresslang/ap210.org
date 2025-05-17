#ifndef SETOFEXTERNAL_DEFINITION_H
#define SETOFEXTERNAL_DEFINITION_H

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

class AP210ARM_API SetOfexternal_definition:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 541};

   private:
      // Required attributes
      class external_definition *_external_definition;

      // Optional attributes

   protected:
      SetOfexternal_definition();

   public:
      ~SetOfexternal_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfexternal_definition *InstanceOf(ARMObject *);
      static SetOfexternal_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfexternal_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
