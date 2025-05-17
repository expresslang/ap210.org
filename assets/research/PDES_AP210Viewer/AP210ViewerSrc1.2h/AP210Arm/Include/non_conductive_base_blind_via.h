#ifndef NON_CONDUCTIVE_BASE_BLIND_VIA_H
#define NON_CONDUCTIVE_BASE_BLIND_VIA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <blind_via.h>

// Unions

// Enumerations

class AP210ARM_API non_conductive_base_blind_via:
public blind_via
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 660};

   private:
      // Required attributes

      // Optional attributes

   protected:
      non_conductive_base_blind_via();

   public:
      ~non_conductive_base_blind_via();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static non_conductive_base_blind_via *InstanceOf(ARMObject *);
      static non_conductive_base_blind_via *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static non_conductive_base_blind_via *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
