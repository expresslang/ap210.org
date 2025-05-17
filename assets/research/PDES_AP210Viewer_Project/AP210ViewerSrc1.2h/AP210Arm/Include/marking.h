#ifndef MARKING_H
#define MARKING_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <marked_message_select.h>
#include <markable_item.h>

// Enumerations

class AP210ARM_API marking:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 640};

   private:
      // Required attributes
      union marked_message_select *_marked_message;
      union markable_item *_marked_device;
      class ee_material *_marking_material;
      class axis_placement *_placement;
      class styled_text *_message_representation;
      class ee_specification *_marking_specification;

      // Optional attributes

   protected:
      marking();

   public:
      ~marking();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static marking *InstanceOf(ARMObject *);
      static marking *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static marking *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
