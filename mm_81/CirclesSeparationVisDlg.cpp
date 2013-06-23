
//
// CirclesSeparationVisDlg.cpp : 
//

#include "stdafx.h"
#include "CirclesSeparationVis.h"
#include "CirclesSeparationVisDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

CCirclesSeparationVisDlg::CCirclesSeparationVisDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCirclesSeparationVisDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	_busy = false;
	_algo_number = 0;
}

void CCirclesSeparationVisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCirclesSeparationVisDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCirclesSeparationVisDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCirclesSeparationVisDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCirclesSeparationVisDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCirclesSeparationVisDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCirclesSeparationVisDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCirclesSeparationVisDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCirclesSeparationVisDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCirclesSeparationVisDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCirclesSeparationVisDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCirclesSeparationVisDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCirclesSeparationVisDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCirclesSeparationVisDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCirclesSeparationVisDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCirclesSeparationVisDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CCirclesSeparationVisDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CCirclesSeparationVisDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CCirclesSeparationVisDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCirclesSeparationVisDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCirclesSeparationVisDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCirclesSeparationVisDlg::OnBnClickedButton20)
	//}}AFX_MSG_MAP
	ON_MESSAGE(UMSG_REDRAW, &CCirclesSeparationVisDlg::OnRedraw)
END_MESSAGE_MAP()


// CCirclesSeparationVisDlg メッセージ ハンドラ

BOOL CCirclesSeparationVisDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CCirclesSeparationVisDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CCirclesSeparationVisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		CDC mem;
		mem.CreateCompatibleDC(&dc);
		CBitmap bmp;
		bmp.CreateCompatibleBitmap(&dc, DRAW_WIDTH, DRAW_HEIGHT);
		mem.SelectObject(&bmp);
		mem.FillSolidRect(0,0,DRAW_WIDTH,DRAW_HEIGHT,RGB(128,128,128));

		LOGFONT font = {};
		font.lfHeight = 20;
		font.lfCharSet = ANSI_CHARSET;
		_tcscpy(font.lfFaceName, _T("Arial"));
		CFont Font;
		Font.CreateFontIndirect(&font);
		mem.SelectObject(Font);

		if (_N > 0 && _N <= 1000) {
			mem.SetBkMode(TRANSPARENT);
			mem.FillSolidRect(0,0,DRAW_WIDTH,DRAW_HEIGHT,RGB(128,128,128));
			CString score;
			score.Format(_T("file: %d, past: %.3f, score: %f"), _file_number, _score, _score);
			mem.SetTextColor(RGB(255,255,255));
			mem.TextOut(DRAW_WIDTH/2 - 50, 20, score);

			CPen pen;
			pen.CreatePen(PS_NULL, 0, RGB(0,0,0));
			mem.SelectObject(pen);

			int i;
			for (i = 0; i < _N; ++i) {
				CBrush brush;
				int color = 255 - (int)(_m[i]*128);
				color = min(255, max(0, color));
				brush.CreateSolidBrush(RGB(0, color/2, color));
				mem.SelectObject(brush);
				mem.Ellipse(gx(_x[i]-_r[i]), gy(_y[i]-_r[i]), gx(_x[i]+_r[i]), gy(_y[i]+_r[i]));
			}

			CPen pen2;
			pen2.CreatePen(PS_SOLID, 0, RGB(255,0,0));
			mem.SelectObject(pen2);
			for (i = 0; i < _N; ++i) {
				mem.MoveTo(gx(_ox[i]), gy(_oy[i]));
				mem.LineTo(gx(_x[i]), gy(_y[i]));
			}

			mem.SetTextColor(RGB(255,255,255));
			for (i = 0; i < _N; ++i) {
				CString c;
				c.Format(_T("%d"), _didx[i]);
				CSize size = mem.GetOutputTextExtent(c);
				mem.TextOut(gx(_x[i]) - size.cx/2, gy(_y[i]) - size.cy/2, c);
			}
		}

		BitBlt(dc.GetSafeHdc(),LEFT_OFFSET,TOP_OFFSET,DRAW_WIDTH,DRAW_HEIGHT, mem.GetSafeHdc(),0,0,SRCCOPY);

		CDialog::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CCirclesSeparationVisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCirclesSeparationVisDlg::OnCancel()
{
	if (_busy) {
		_stop = true;
		Sleep(200);
	}
	CDialog::OnCancel();
}

LRESULT CCirclesSeparationVisDlg::OnRedraw(WPARAM wParam, LPARAM lParam)
{
	Invalidate(FALSE);
	return 0;
}

void CCirclesSeparationVisDlg::OnBnClickedButton1()
{
	Run(1);
}

void CCirclesSeparationVisDlg::OnBnClickedButton2()
{
	Run(2);
}

void CCirclesSeparationVisDlg::OnBnClickedButton3()
{
	Run(3);
}

void CCirclesSeparationVisDlg::OnBnClickedButton4()
{
	Run(4);
}

void CCirclesSeparationVisDlg::OnBnClickedButton5()
{
	Run(5);
}

void CCirclesSeparationVisDlg::OnBnClickedButton6()
{
	Run(6);
}

void CCirclesSeparationVisDlg::OnBnClickedButton7()
{
	Run(7);
}

void CCirclesSeparationVisDlg::OnBnClickedButton8()
{
	Run(8);
}

void CCirclesSeparationVisDlg::OnBnClickedButton9()
{
	Run(9);
}

void CCirclesSeparationVisDlg::OnBnClickedButton10()
{
	Run(10);
}

void CCirclesSeparationVisDlg::OnBnClickedButton11()
{
	Run(11);
}

void CCirclesSeparationVisDlg::OnBnClickedButton12()
{
	Run(12);
}

void CCirclesSeparationVisDlg::OnBnClickedButton13()
{
	Run(13);
}

void CCirclesSeparationVisDlg::OnBnClickedButton14()
{
	Run(14);
}

void CCirclesSeparationVisDlg::OnBnClickedButton15()
{
	Run(15);
}

void CCirclesSeparationVisDlg::OnBnClickedButton16()
{
	Run(16);
}

void CCirclesSeparationVisDlg::OnBnClickedButton17()
{
	Run(17);
}

void CCirclesSeparationVisDlg::OnBnClickedButton18()
{
	Run(18);
}

void CCirclesSeparationVisDlg::OnBnClickedButton19()
{
	Run(19);
}

void CCirclesSeparationVisDlg::OnBnClickedButton20()
{
	Run(20);
}

bool CCirclesSeparationVisDlg::LoadFromFile(int index)
{
	char filename[256];
	sprintf(filename, "%d.in", index);
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		return false;
	}

	char buffer[1024];
	fgets(buffer, 1024, fp);
	int N = atoi(buffer);
	_x.resize(N);
	_y.resize(N);
	_r.resize(N);
	_m.resize(N);
	_didx.resize(N);
	int i;
	for (i = 0; i < N; i++) {
		fgets(buffer, 1024, fp);
		sscanf(buffer, "%lf %lf %lf %lf", &_x[i], &_y[i], &_r[i], &_m[i]);
		_didx[i] = i;
	}
	fclose(fp);

	cs.initialize(_x, _y, _r, _m);

	_N = N;
	_ox = _x;
	_oy = _y;

	return true;
}

void CCirclesSeparationVisDlg::Run(int index)
{
	if (_busy) {
		_stop = true;
		return;
	}

	_algo_number = 1;
	_file_number = index;

	if (!LoadFromFile(_file_number)) {
		return;
	}

	_busy = true;
	_stop = false;
	UINT (__cdecl CCirclesSeparationVisDlg::*f)(void) = &CCirclesSeparationVisDlg::_Run;
	CWinThread *thread = AfxBeginThread( (AFX_THREADPROC)(*((void **)&f)), this );
}

UINT __cdecl CCirclesSeparationVisDlg::_Run()
{
	IntVec order = cs.gen_process_order_1();
	_didx = cs.get_display_order(order);
	cs.place_1(order);

	_score = -1;

	double start = GetTickCount();
	const int Seconds = 10;
	const int Tick = 10;
	for (int t = 0; !_stop && t < (Seconds*1000/Tick); ++t) {
		DIVec ev;
		cs.move_1(order, _x, _y);
		_score = cs.evaluate(_x, _y, ev);

		Sleep(Tick);
		_past = (double)(GetTickCount() - start) * 0.001;
		PostMessage(UMSG_REDRAW);
	}

	_busy = false;
	return 0;
}

