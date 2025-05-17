#ifndef ALTERED_PACKAGE_H
#define ALTERED_PACKAGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <package.h>

// Unions

// Enumerations

class AP210ARM_API altered_package:
public package
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 60};

   private:
      // Required attributes
      class package *_package_to_be_altered;

      // Optional attributes

   protected:
      altered_package();

   public:
      ~altered_package();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static altered_package *InstanceOf(ARMObject *);
      static altered_package *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static altered_package *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
