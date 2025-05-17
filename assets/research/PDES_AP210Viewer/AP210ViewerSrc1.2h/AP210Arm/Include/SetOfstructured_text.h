#ifndef SETOFSTRUCTURED_TEXT_H
#define SETOFSTRUCTURED_TEXT_H

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

class AP210ARM_API SetOfstructured_text:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 19};

   private:
      // Required attributes
      class structured_text *_structured_text;

      // Optional attributes

   protected:
      SetOfstructured_text();

   public:
      ~SetOfstructured_text();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfstructured_text *InstanceOf(ARMObject *);
      static SetOfstructured_text *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfstructured_text *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
