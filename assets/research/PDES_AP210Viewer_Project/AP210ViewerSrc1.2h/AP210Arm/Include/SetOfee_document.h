#ifndef SETOFEE_DOCUMENT_H
#define SETOFEE_DOCUMENT_H

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

class AP210ARM_API SetOfee_document:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 17};

   private:
      // Required attributes
      class ee_document *_ee_document;

      // Optional attributes

   protected:
      SetOfee_document();

   public:
      ~SetOfee_document();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfee_document *InstanceOf(ARMObject *);
      static SetOfee_document *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfee_document *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
