#ifndef BOOLEAN_CSG_RESULT_H
#define BOOLEAN_CSG_RESULT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <boolean_csg_operand.h>
#include <boolean_csg_operand.h>

// Enumerations
#include <boolean_operator.h>

class AP210ARM_API boolean_csg_result:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 242};

   private:
      // Required attributes
      union boolean_csg_operand *_operand_1;
      union boolean_csg_operand *_operand_2;
      boolean_operator::boolean_operator _csg_operator;

      // Optional attributes

   protected:
      boolean_csg_result();

   public:
      ~boolean_csg_result();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static boolean_csg_result *InstanceOf(ARMObject *);
      static boolean_csg_result *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static boolean_csg_result *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
