#ifndef SETOFEE_TEXT_H
#define SETOFEE_TEXT_H

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

class AP210ARM_API SetOfee_text:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 286};

   private:
      // Required attributes
      class ee_text *_ee_text;

      // Optional attributes

   protected:
      SetOfee_text();

   public:
      ~SetOfee_text();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfee_text *InstanceOf(ARMObject *);
      static SetOfee_text *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfee_text *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
