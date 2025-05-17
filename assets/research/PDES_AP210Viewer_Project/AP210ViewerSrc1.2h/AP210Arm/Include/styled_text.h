#ifndef STYLED_TEXT_H
#define STYLED_TEXT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <feature_shape_definition.h>

// Unions
#include <font_select.h>

// Enumerations

class AP210ARM_API styled_text:
public feature_shape_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 643};

   private:
      // Required attributes
      union font_select *_text_font;

      // Optional attributes

   protected:
      styled_text();

   public:
      ~styled_text();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static styled_text *InstanceOf(ARMObject *);
      static styled_text *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static styled_text *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
