#ifndef SETOFMODEL_PARAMETER_H
#define SETOFMODEL_PARAMETER_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfmodel_parameter:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 55};

   private:
      // Required attributes
      class model_parameter *_model_parameter;

      // Optional attributes

   protected:
      SetOfmodel_parameter();

   public:
      ~SetOfmodel_parameter();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfmodel_parameter *InstanceOf(ARMObject *);
      static SetOfmodel_parameter *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfmodel_parameter *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
