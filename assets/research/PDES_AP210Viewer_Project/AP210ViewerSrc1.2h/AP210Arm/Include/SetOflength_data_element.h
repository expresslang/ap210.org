#ifndef SETOFLENGTH_DATA_ELEMENT_H
#define SETOFLENGTH_DATA_ELEMENT_H

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

class AP210ARM_API SetOflength_data_element:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 842};

   private:
      // Required attributes
      class length_data_element *_length_data_element;

      // Optional attributes

   protected:
      SetOflength_data_element();

   public:
      ~SetOflength_data_element();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOflength_data_element *InstanceOf(ARMObject *);
      static SetOflength_data_element *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOflength_data_element *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
