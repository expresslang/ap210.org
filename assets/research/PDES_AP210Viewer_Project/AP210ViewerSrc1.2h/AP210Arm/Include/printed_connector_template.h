#ifndef PRINTED_CONNECTOR_TEMPLATE_H
#define PRINTED_CONNECTOR_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <printed_part_template.h>

// Unions

// Enumerations

class AP210ARM_API printed_connector_template:
public printed_part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 606};

   private:
      // Required attributes

      // Optional attributes

   protected:
      printed_connector_template();

   public:
      ~printed_connector_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_connector_template *InstanceOf(ARMObject *);
      static printed_connector_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_connector_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
