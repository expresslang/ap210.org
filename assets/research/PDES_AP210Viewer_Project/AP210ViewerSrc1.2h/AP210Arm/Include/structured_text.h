#ifndef STRUCTURED_TEXT_H
#define STRUCTURED_TEXT_H

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

class AP210ARM_API structured_text:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 20};

   private:
      // Required attributes
      class external_definition *_content_markup;

      // Optional attributes
      class ee_text *_plain_text_content;
      class structured_text *_precedent_structured_text;
      class structured_text *_structured_text_content[2000];

   protected:
      structured_text();

   public:
      ~structured_text();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static structured_text *InstanceOf(ARMObject *);
      static structured_text *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static structured_text *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
