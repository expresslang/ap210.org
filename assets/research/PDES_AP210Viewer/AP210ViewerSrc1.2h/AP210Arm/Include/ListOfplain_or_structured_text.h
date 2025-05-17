#ifndef LISTOFPLAIN_OR_STRUCTURED_TEXT_H
#define LISTOFPLAIN_OR_STRUCTURED_TEXT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <plain_or_structured_text.h>

// Enumerations

class AP210ARM_API ListOfplain_or_structured_text:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 24};

   private:
      // Required attributes
      union plain_or_structured_text *_plain_or_structured_text;

      // Optional attributes

   protected:
      ListOfplain_or_structured_text();

   public:
      ~ListOfplain_or_structured_text();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ListOfplain_or_structured_text *InstanceOf(ARMObject *);
      static ListOfplain_or_structured_text *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ListOfplain_or_structured_text *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
