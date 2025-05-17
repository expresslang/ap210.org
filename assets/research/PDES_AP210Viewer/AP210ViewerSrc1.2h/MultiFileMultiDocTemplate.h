// MultiFileMultiDocTemplate.h: interface for the CMultiFileMultiDocTemplate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIFILEMULTIDOCTEMPLATE_H__E8B6FEA2_5FE6_11D3_9B0E_0080AD428934__INCLUDED_)
#define AFX_MULTIFILEMULTIDOCTEMPLATE_H__E8B6FEA2_5FE6_11D3_9B0E_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CMultiFileMultiDocTemplate : public CMultiDocTemplate {
public:
   CMultiFileMultiDocTemplate(
      UINT nIDResource, CRuntimeClass* pDocClass,
      CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);
   virtual ~CMultiFileMultiDocTemplate();

   BOOL GetDocString(CString& rString, enum DocStringIndex i) const;
   CDocTemplate::Confidence MatchDocType(const char* pszPathName, CDocument*& rpDocMatch);
   };

#endif // !defined(AFX_MULTIFILEMULTIDOCTEMPLATE_H__E8B6FEA2_5FE6_11D3_9B0E_0080AD428934__INCLUDED_)
