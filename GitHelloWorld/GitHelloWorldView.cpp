
// GitHelloWorldView.cpp : implementation of the CGitHelloWorldView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GitHelloWorld.h"
#endif

#include "GitHelloWorldDoc.h"
#include "GitHelloWorldView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGitHelloWorldView

IMPLEMENT_DYNCREATE(CGitHelloWorldView, CView)

BEGIN_MESSAGE_MAP(CGitHelloWorldView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGitHelloWorldView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGitHelloWorldView construction/destruction

CGitHelloWorldView::CGitHelloWorldView()
{
	// TODO: add construction code here

}

CGitHelloWorldView::~CGitHelloWorldView()
{
}

BOOL CGitHelloWorldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGitHelloWorldView drawing

void CGitHelloWorldView::OnDraw(CDC* /*pDC*/)
{
	CGitHelloWorldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CGitHelloWorldView printing


void CGitHelloWorldView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGitHelloWorldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGitHelloWorldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGitHelloWorldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CGitHelloWorldView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGitHelloWorldView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGitHelloWorldView diagnostics

#ifdef _DEBUG
void CGitHelloWorldView::AssertValid() const
{
	CView::AssertValid();
}

void CGitHelloWorldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGitHelloWorldDoc* CGitHelloWorldView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGitHelloWorldDoc)));
	return (CGitHelloWorldDoc*)m_pDocument;
}
#endif //_DEBUG


// CGitHelloWorldView message handlers
