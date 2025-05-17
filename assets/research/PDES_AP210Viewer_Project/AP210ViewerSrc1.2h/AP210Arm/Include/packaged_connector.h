#ifndef PACKAGED_CONNECTOR_H
#define PACKAGED_CONNECTOR_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <packaged_part.h>

// Unions

// Enumerations

class AP210ARM_API packaged_connector:
public packaged_part
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 607};

   private:
      // Required attributes

      // Optional attributes
      class seating_plane *_interface_plane;

   protected:
      packaged_connector();

   public:
      ~packaged_connector();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static packaged_connector *InstanceOf(ARMObject *);
      static packaged_connector *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static packaged_connector *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
