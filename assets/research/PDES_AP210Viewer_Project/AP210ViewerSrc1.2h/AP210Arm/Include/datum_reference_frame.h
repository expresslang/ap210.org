#ifndef DATUM_REFERENCE_FRAME_H
#define DATUM_REFERENCE_FRAME_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <non_feature_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API datum_reference_frame:
public non_feature_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 142};

   private:
      // Required attributes
      class datum_plane *_reference_planes[2000];
      class datum_axis *_reference_axes[2000];

      // Optional attributes
      class datum_point *_reference_origin;

   protected:
      datum_reference_frame();

   public:
      ~datum_reference_frame();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_reference_frame *InstanceOf(ARMObject *);
      static datum_reference_frame *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_reference_frame *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
