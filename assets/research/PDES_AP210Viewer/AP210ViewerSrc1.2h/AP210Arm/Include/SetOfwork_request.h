#ifndef SETOFWORK_REQUEST_H
#define SETOFWORK_REQUEST_H

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

class AP210ARM_API SetOfwork_request:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 265};

   private:
      // Required attributes
      class work_request *_work_request;

      // Optional attributes

   protected:
      SetOfwork_request();

   public:
      ~SetOfwork_request();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfwork_request *InstanceOf(ARMObject *);
      static SetOfwork_request *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfwork_request *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
