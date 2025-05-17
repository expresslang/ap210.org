#ifndef LISTOFPRINTED_PART_TEMPLATE_MATERIAL_H
#define LISTOFPRINTED_PART_TEMPLATE_MATERIAL_H

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

class AP210ARM_API ListOfprinted_part_template_material:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 173};

   private:
      // Required attributes
      class printed_part_template_material *_printed_part_template_material;

      // Optional attributes

   protected:
      ListOfprinted_part_template_material();

   public:
      ~ListOfprinted_part_template_material();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ListOfprinted_part_template_material *InstanceOf(ARMObject *);
      static ListOfprinted_part_template_material *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ListOfprinted_part_template_material *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
