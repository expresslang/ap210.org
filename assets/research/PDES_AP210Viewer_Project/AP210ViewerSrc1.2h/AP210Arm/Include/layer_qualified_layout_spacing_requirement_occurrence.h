#ifndef LAYER_QUALIFIED_LAYOUT_SPACING_REQUIREMENT_OCCURRENCE_H
#define LAYER_QUALIFIED_LAYOUT_SPACING_REQUIREMENT_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <layout_spacing_requirement_occurrence.h>

// Unions

// Enumerations

class AP210ARM_API layer_qualified_layout_spacing_requirement_occurrence:
public layout_spacing_requirement_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 628};

   private:
      // Required attributes
      class inter_stratum_extent *_layer_context[2000];

      // Optional attributes

   protected:
      layer_qualified_layout_spacing_requirement_occurrence();

   public:
      ~layer_qualified_layout_spacing_requirement_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static layer_qualified_layout_spacing_requirement_occurrence *InstanceOf(ARMObject *);
      static layer_qualified_layout_spacing_requirement_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static layer_qualified_layout_spacing_requirement_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
