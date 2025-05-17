#ifndef LISTOFSCALAR_TERMINAL_DEFINITION_H
#define LISTOFSCALAR_TERMINAL_DEFINITION_H

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

class AP210ARM_API ListOfscalar_terminal_definition:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 98};

   private:
      // Required attributes
      class scalar_terminal_definition *_scalar_terminal_definition;

      // Optional attributes

   protected:
      ListOfscalar_terminal_definition();

   public:
      ~ListOfscalar_terminal_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ListOfscalar_terminal_definition *InstanceOf(ARMObject *);
      static ListOfscalar_terminal_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ListOfscalar_terminal_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
