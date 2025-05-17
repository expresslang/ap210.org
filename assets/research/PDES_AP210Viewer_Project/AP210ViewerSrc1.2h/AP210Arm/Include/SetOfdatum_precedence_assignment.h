#ifndef SETOFDATUM_PRECEDENCE_ASSIGNMENT_H
#define SETOFDATUM_PRECEDENCE_ASSIGNMENT_H

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

class AP210ARM_API SetOfdatum_precedence_assignment:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 147};

   private:
      // Required attributes
      class datum_precedence_assignment *_datum_precedence_assignment;

      // Optional attributes

   protected:
      SetOfdatum_precedence_assignment();

   public:
      ~SetOfdatum_precedence_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfdatum_precedence_assignment *InstanceOf(ARMObject *);
      static SetOfdatum_precedence_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfdatum_precedence_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
