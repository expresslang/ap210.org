#ifndef QUALIFIED_DATA_ELEMENT_H
#define QUALIFIED_DATA_ELEMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <data_element.h>

// Unions

// Enumerations

class AP210ARM_API qualified_data_element:
public data_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 746};

   private:
      // Required attributes

      // Optional attributes

   protected:
      qualified_data_element();

   public:
      ~qualified_data_element();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static qualified_data_element *InstanceOf(ARMObject *);
      static qualified_data_element *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static qualified_data_element *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
