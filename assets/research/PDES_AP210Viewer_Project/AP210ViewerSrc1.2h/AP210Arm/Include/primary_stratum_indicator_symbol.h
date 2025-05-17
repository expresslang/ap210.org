#ifndef PRIMARY_STRATUM_INDICATOR_SYMBOL_H
#define PRIMARY_STRATUM_INDICATOR_SYMBOL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <special_symbol_laminate_component.h>

// Unions

// Enumerations

class AP210ARM_API primary_stratum_indicator_symbol:
public special_symbol_laminate_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 723};

   private:
      // Required attributes

      // Optional attributes

   protected:
      primary_stratum_indicator_symbol();

   public:
      ~primary_stratum_indicator_symbol();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static primary_stratum_indicator_symbol *InstanceOf(ARMObject *);
      static primary_stratum_indicator_symbol *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static primary_stratum_indicator_symbol *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
