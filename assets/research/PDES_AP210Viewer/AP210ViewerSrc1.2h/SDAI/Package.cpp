// Package.cpp: implementation of the Package class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
// drawing
#include "../AP210ViewerDoc.h"
#include "../AP210ViewerView.h"
#include "..\OpenGL\Tess.h"

#include "Package.h"
#include "PackagedComponent.h"
#include "ExtractGeometry.h"
#include "ap210_visualizer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Package *Package::Construct(PWBDataBase *PWB,
                            SdaiAppInstance package) {
   Package *p;
   AP210ObjectListItor itor(&(PWB->Packages));

   // look for an existing package
   while((p = (Package *)itor.NextInstanceOf(Package::TypeID())) != NULL) {
      if (p->PackageRef == package) {
         return p;
         }
      }
   // create a new package
   p = new Package(PWB, package);
   PWB->Packages.Add(p);
   return p;
   }

Package::Package(PWBDataBase *PWB, SdaiAppInstance package):
PhysicalUnit(PWB, package) {
   PackageRef = package;
   }

Package::~Package() {
   }
int Package::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return PhysicalUnit::DynamicType(ID);
   }
#ifdef INSTANCEOF
Package *Package::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(Package *)s;
   return 0;
   }
Package *Package::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(Package *)s;
   return 0;
   }
#endif
//
//	OutputGlError
//
void Package::OutputGlError(char* label) {
	GLenum errorno = glGetError() ;
	if (errorno != GL_NO_ERROR) {
		TRACE("Package: %s had error: #(%d) %s\r\n", label, errorno, gluErrorString(errorno)) ;
	}
}

SdaiAppInstance Package::getShape(SdaiModel AP210Model) {
   SdaiAppInstance psr = sdaiNULL; // package  shape_representation
   psr = getPackageGeometry(AP210Model, PackageRef);
#ifdef VERBOSE
TRACE("In Package::getShape()\r\n");
TRACE(" PackageRef: %s\r\n", _sdaiGetPart21Description(PackageRef));
TRACE(" psr 1: %s\r\n", _sdaiGetPart21Description(psr));
#endif
   if (psr == sdaiNULL) {
      // Look for rockwell shape_representations here.
      psr = getComponentDefinitionShapeRepresentation(AP210Model, PackageRef);
 
#ifdef VERBOSE
TRACE("psr 2: %s\r\n", _sdaiGetPart21Description(psr));
#endif
      }
  return psr; 
  }
void Package::Select(AP210ObjectListItor *PCitor) {
TRACE("Selected %s\r\n", PartNumber);
   // Search for components 
   PackagedComponent *pc;
   PCitor->Reset();
   while((pc = (PackagedComponent *)PCitor->NextDirectInstanceOf(PackagedComponent::TypeID())) != NULL) {
      if (pc->PackageRef == this) {
TRACE("  Selected %s\r\n", pc->getName());
         pc->Select();
         }
      }
   }

// Height functionality
void Package::setHeight(double height) {
   if (getHeight() != height) {
      setPackageHeight(DataBase->AP210Model, PackageRef, height);
      setReDrawStatus();
      DataBase->SetModifiedFlag(TRUE);
      }
   }
double Package::getHeight() {
#ifdef VERBOSE
TRACE("In Package::getHeight()\r\n");
TRACE(" PackageRef: 0x%08x\r\n", PackageRef);
#endif
   return getPackageHeight(DataBase->AP210Model, PackageRef);
   }
