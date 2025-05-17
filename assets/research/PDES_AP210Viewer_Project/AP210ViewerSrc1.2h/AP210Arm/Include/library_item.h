#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

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

class AP210ARM_API library_item:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 155};

   private:
      // Required attributes
      STR _library;

      // Optional attributes
      STR _item_version;
      STR _item_name;

   protected:
      library_item();

   public:
      ~library_item();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static library_item *InstanceOf(ARMObject *);
      static library_item *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static library_item *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
