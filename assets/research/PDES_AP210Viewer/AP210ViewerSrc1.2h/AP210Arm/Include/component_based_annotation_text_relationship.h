#ifndef COMPONENT_BASED_ANNOTATION_TEXT_RELATIONSHIP_H
#define COMPONENT_BASED_ANNOTATION_TEXT_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <component_feature_to_layout_feature_relationship.h>

// Unions

// Enumerations
#include <component_based_message_type.h>

class AP210ARM_API component_based_annotation_text_relationship:
public component_feature_to_layout_feature_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 303};

   private:
      // Required attributes
      component_based_message_type::component_based_message_type _message_type;

      // Optional attributes

   protected:
      component_based_annotation_text_relationship();

   public:
      ~component_based_annotation_text_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_based_annotation_text_relationship *InstanceOf(ARMObject *);
      static component_based_annotation_text_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_based_annotation_text_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
