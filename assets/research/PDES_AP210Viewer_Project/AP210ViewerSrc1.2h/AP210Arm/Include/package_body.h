#ifndef PACKAGE_BODY_H
#define PACKAGE_BODY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_feature.h>

// Unions

// Enumerations

class AP210ARM_API package_body:
public part_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 665};

   private:
      // Required attributes
      class ee_material *_body_material;

      // Optional attributes

   protected:
      package_body();

   public:
      ~package_body();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static package_body *InstanceOf(ARMObject *);
      static package_body *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static package_body *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
