#ifndef ELECTRICAL_ISOLATION_REMOVAL_STRUCTURE_H
#define ELECTRICAL_ISOLATION_REMOVAL_STRUCTURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <filled_area_material_removal_structure.h>

// Unions

// Enumerations

class AP210ARM_API electrical_isolation_removal_structure:
public filled_area_material_removal_structure
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 526};

   private:
      // Required attributes
      class ee_requirement_occurrence *_electrical_isolation_spacing_requirement;

      // Optional attributes

   protected:
      electrical_isolation_removal_structure();

   public:
      ~electrical_isolation_removal_structure();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static electrical_isolation_removal_structure *InstanceOf(ARMObject *);
      static electrical_isolation_removal_structure *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static electrical_isolation_removal_structure *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
