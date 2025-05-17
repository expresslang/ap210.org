#ifndef REGISTERED_STYLE_H
#define REGISTERED_STYLE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API registered_style:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 71};

   private:
      // Required attributes
      STR _case_style_code;
      class ee_document *_registration_document;

      // Optional attributes

   protected:
      registered_style();

   public:
      ~registered_style();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static registered_style *InstanceOf(ARMObject *);
      static registered_style *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static registered_style *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
