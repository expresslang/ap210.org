#ifndef DESIGN_LAYER_STRATUM_H
#define DESIGN_LAYER_STRATUM_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <stratum.h>

// Unions

// Enumerations

class AP210ARM_API design_layer_stratum:
public stratum
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 370};

   private:
      // Required attributes
      RoseBoolean _primary_design_layer_stratum;

      // Optional attributes

   protected:
      design_layer_stratum();

   public:
      ~design_layer_stratum();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static design_layer_stratum *InstanceOf(ARMObject *);
      static design_layer_stratum *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static design_layer_stratum *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
