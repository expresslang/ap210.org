// NonPlatedThruHole.h: interface for the NonPlatedThruHole class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NonPlatedThruHole_H__585868A3_B24A_11D4_8A9A_0080AD428934__INCLUDED_)
#define AFX_NonPlatedThruHole_H__585868A3_B24A_11D4_8A9A_0080AD428934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AP210GraphicObject.h"
#include "AP210ObjectList.h"	// Added by ClassView

/*
 * The list of variables could be needed/added for 
 * Component placement restriction assignment
 * ComponentsPermitted already has been. Might need
 * a class for Component placement restriction assignment.
 *
 *  maximum mounting clearance
 *  maximum negative component height
 *  maximum positive component height
 *  minimum mounting clearance
 *  requirement
 */
class NonPlatedThruHole : public AP210GraphicObject {
   protected:
      enum {typeID = baseID + 13};

   protected:
      // WARNING: Duplicated in MountingRestrictArea
      //          Need to deal with this when MountingRestrictArea
      //          finished.
      double m[16];  // OpenGL transformation matrix
	  virtual void RenderCaps();
	  virtual void RenderSides();
	  void applyTranslationMatrix();

   private: 
	   CString getSurface();
	   SdaiAppInstance ComponentDefinition;
	   virtual SdaiAppInstance getShape();
      // WARNING: Duplicated in MountingRestrictArea
      //          Need to deal with this when MountingRestrictArea
      //          finished.
	   AP210LP * matchLine(AP210Point *p);
	   void sortLines();
	   void getPoints();
      // shape information not required after points created!
      // unless you want to edit them.
      AP210ObjectList Lines;

      SdaiAppInstance MaximumPositiveComponentHeight;
      BOOL ComponentsPermitted;
      NonPlatedThruHole(PWBDataBase *PWB, SdaiAppInstance npth);
   public:
      virtual ~NonPlatedThruHole();

   public:
      int DynamicType(int ID);
      virtual int GetTypeID() {return typeID;};
      static int TypeID() {return typeID;};
#ifdef INSTANCEOF
      static NonPlatedThruHole *DirectInstanceOf(AP210Object *);
      static NonPlatedThruHole *InstanceOf(AP210Object *);
#endif
   public:  
	   double getHeight();
      static void Construct(PWBDataBase *PWB, SdaiNPL npthList);
      static NonPlatedThruHole *Construct(PWBDataBase *PWB,
                                                SdaiAppInstance npth);

      // WARNING: Duplicated in MountingRestrictArea
      //          Need to deal with this when MountingRestrictArea
      //          finished.
      // placement
      ComponentPlacement Side;
	   virtual void setSeatingPlane(double base);
      virtual void Draw(double Base = 0.0);

   };
#endif // !defined(AFX_NonPlatedThruHole_H__585868A3_B24A_11D4_8A9A_0080AD428934__INCLUDED_)
