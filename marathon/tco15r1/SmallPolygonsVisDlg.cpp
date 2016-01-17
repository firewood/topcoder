
// SmallPolygonsVisDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SmallPolygonsVis.h"
#include "SmallPolygonsVisDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSmallPolygonsVisDlg dialog



CSmallPolygonsVisDlg::CSmallPolygonsVisDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSmallPolygonsVisDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSmallPolygonsVisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSmallPolygonsVisDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CSmallPolygonsVisDlg message handlers

BOOL CSmallPolygonsVisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	IISet s;
	for (int i = 0; i < 100; ++i) {
		int x = (rand() * MAX_COORDINATE) / (RAND_MAX + 1);
		int y = (rand() * MAX_COORDINATE) / (RAND_MAX + 1);
		s.insert(II(x, y));
	}

	int N = 10;
	int Np = s.size();
	std::vector<int> points;
	for (auto p : s) {
		points.push_back(p.first);
		points.push_back(p.second);
	}

	m_sp.init(points, N);
	m_sp.findTriangles();
	m_sp.chooseFirstPolygon();

	for (int i = 0; i < 100; ++i) {
		m_sp.chooseNextVertex();
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSmallPolygonsVisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);

		CDC mem;
		mem.CreateCompatibleDC(&dc);
		CBitmap bmp;
		bmp.CreateCompatibleBitmap(&dc, DRAW_WIDTH, DRAW_HEIGHT);
		mem.SelectObject(&bmp);
		mem.SetBkMode(TRANSPARENT);
		mem.FillSolidRect(0, 0, DRAW_WIDTH, DRAW_HEIGHT, RGB(128, 128, 128));

		LOGFONT font = {};
		font.lfHeight = 12;
		font.lfCharSet = ANSI_CHARSET;
		_tcscpy(font.lfFaceName, _T("Terminal"));
		CFont Font;
		Font.CreateFontIndirect(&font);
		mem.SelectObject(Font);

		for (int i = 0; i < m_sp.Np; ++i) {
			int x = m_sp.x[i], y = m_sp.y[i];
			x = (x * DRAW_WIDTH) / MAX_COORDINATE;
			y = (y * DRAW_HEIGHT) / MAX_COORDINATE;
			TCHAR w[64];
			_stprintf(w, _T("%d"), i);
			mem.SetTextColor(RGB(255, 255, 255));
			mem.TextOut(x + 4, y, w);
		}

		CPen line;
		line.CreatePen(PS_SOLID, 0, RGB(0, 255, 0));
		mem.SelectObject(line);
		for (int start_node : m_sp.polygons) {
			int x = m_sp.x[start_node], y = m_sp.y[start_node];
			x = (x * DRAW_WIDTH) / MAX_COORDINATE;
			y = (y * DRAW_HEIGHT) / MAX_COORDINATE;
			mem.MoveTo(x, y);
			int node = start_node;
			do {
				int next_node = m_sp.connection[node].next;
				int x = m_sp.x[next_node], y = m_sp.y[next_node];
				x = (x * DRAW_WIDTH) / MAX_COORDINATE;
				y = (y * DRAW_HEIGHT) / MAX_COORDINATE;
				mem.LineTo(x, y);
				node = m_sp.connection[node].next;
			} while (node != start_node);
		}

		CBrush brush;
		brush.CreateSolidBrush(RGB(255, 0, 0));

		for (int start_node : m_sp.polygons) {
			int node = start_node;
			do {
				mem.SelectObject(brush);
				int x = m_sp.x[node], y = m_sp.y[node];
				x = (x * DRAW_WIDTH) / MAX_COORDINATE;
				y = (y * DRAW_HEIGHT) / MAX_COORDINATE;
				mem.Ellipse(x - 2, y - 2, x + 2, y + 2);

				node = m_sp.connection[node].next;
			} while (node != start_node);
		}

		BitBlt(dc.GetSafeHdc(), LEFT_OFFSET, TOP_OFFSET, DRAW_WIDTH, DRAW_HEIGHT, mem.GetSafeHdc(), 0, 0, SRCCOPY);

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSmallPolygonsVisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSmallPolygonsVisDlg::OnOK()
{
	m_sp.chooseNextVertex();
	Invalidate();
}
