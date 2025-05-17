#ifndef CONFIGURATION_CONTROLLED_MESSAGE_H
#define CONFIGURATION_CONTROLLED_MESSAGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <message_source_select.h>

// Enumerations
#include <message_type.h>

class AP210ARM_API configuration_controlled_message:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 382};

   private:
      // Required attributes
      union message_source_select *_message_source;
      STR _message_content;
      message_type::message_type _message_type_specification;

      // Optional attributes

   protected:
      configuration_controlled_message();

   public:
      ~configuration_controlled_message();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static configuration_controlled_message *InstanceOf(ARMObject *);
      static configuration_controlled_message *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static configuration_controlled_message *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
