#ifndef START_REQUEST_H
#define START_REQUEST_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <work_request.h>

// Unions

// Enumerations

class AP210ARM_API start_request:
public work_request
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 793};

   private:
      // Required attributes

      // Optional attributes

   protected:
      start_request();

   public:
      ~start_request();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static start_request *InstanceOf(ARMObject *);
      static start_request *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static start_request *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
