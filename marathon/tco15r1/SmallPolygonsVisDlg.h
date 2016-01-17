
// SmallPolygonsVisDlg.h : header file
//

#pragma once


#define LEFT_OFFSET 120
#define TOP_OFFSET 12
#define DRAW_WIDTH 1000
#define DRAW_HEIGHT 1000


#include "SmallPolygons.h"


// CSmallPolygonsVisDlg dialog
class CSmallPolygonsVisDlg : public CDialogEx
{
	SmallPolygons m_sp;

// Construction
public:
	CSmallPolygonsVisDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SMALLPOLYGONSVIS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void OnOK();
};
