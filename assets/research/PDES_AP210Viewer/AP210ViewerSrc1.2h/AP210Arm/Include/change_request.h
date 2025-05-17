#ifndef CHANGE_REQUEST_H
#define CHANGE_REQUEST_H

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

class AP210ARM_API change_request:
public work_request
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 284};

   private:
      // Required attributes
      class ee_text *_consequence[2000];
      STR _version;

      // Optional attributes
      union design_object_management_relationship_or_description *_recommended_solution[2000];

   protected:
      change_request();

   public:
      ~change_request();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static change_request *InstanceOf(ARMObject *);
      static change_request *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static change_request *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
