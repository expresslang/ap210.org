#ifndef SETOFCONDUCTIVE_INTERCONNECT_ELEMENT_H
#define SETOFCONDUCTIVE_INTERCONNECT_ELEMENT_H

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

class AP210ARM_API SetOfconductive_interconnect_element:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 693};

   private:
      // Required attributes
      class conductive_interconnect_element *_conductive_interconnect_element;

      // Optional attributes

   protected:
      SetOfconductive_interconnect_element();

   public:
      ~SetOfconductive_interconnect_element();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfconductive_interconnect_element *InstanceOf(ARMObject *);
      static SetOfconductive_interconnect_element *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfconductive_interconnect_element *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
