#ifndef REGISTERED_FONT_H
#define REGISTERED_FONT_H

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

class AP210ARM_API registered_font:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 644};

   private:
      // Required attributes
      class ee_document *_registration_document;
      STR _font_code;

      // Optional attributes

   protected:
      registered_font();

   public:
      ~registered_font();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static registered_font *InstanceOf(ARMObject *);
      static registered_font *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static registered_font *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
