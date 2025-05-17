#ifndef LAMINATE_TEXT_STRING_COMPONENT_H
#define LAMINATE_TEXT_STRING_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <array_placement_group.h>
#include <laminate_component.h>

// Unions

// Enumerations
#include <horizontal_justification.h>
#include <vertical_justification.h>

class AP210ARM_API laminate_text_string_component:
public array_placement_group,
public laminate_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 624};

   private:
      // Required attributes
      STR _message;
      horizontal_justification::horizontal_justification _of_horizontal_justification;
      vertical_justification::vertical_justification _of_vertical_justification;

      // Optional attributes

   protected:
      laminate_text_string_component();

   public:
      ~laminate_text_string_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static laminate_text_string_component *InstanceOf(ARMObject *);
      static laminate_text_string_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static laminate_text_string_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
