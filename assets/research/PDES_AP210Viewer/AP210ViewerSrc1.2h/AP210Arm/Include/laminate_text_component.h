#ifndef LAMINATE_TEXT_COMPONENT_H
#define LAMINATE_TEXT_COMPONENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <laminate_component.h>

// Unions

// Enumerations

class AP210ARM_API laminate_text_component:
public laminate_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 623};

   private:
      // Required attributes
      STR _of_character;
      class stratum_feature *_stratum_feature_implementation[2000];

      // Optional attributes

   protected:
      laminate_text_component();

   public:
      ~laminate_text_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static laminate_text_component *InstanceOf(ARMObject *);
      static laminate_text_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static laminate_text_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
