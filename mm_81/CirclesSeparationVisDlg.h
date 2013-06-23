
#pragma once

#include "CirclesSeparation.h"

#define LEFT_X -1.50
#define RIGHT_X 1.50
#define TOP_Y 1.50
#define BOTTOM_Y -1.50
#define LEFT_OFFSET 120
#define TOP_OFFSET 12
#define DRAW_WIDTH 1000
#define DRAW_HEIGHT 1000

enum {
	UMSG_REDRAW = WM_APP,
};

class CCirclesSeparationVisDlg : public CDialog
{
	bool _busy;
	bool _stop;
	bool _failed;
	int _algo_number;
	int _file_number;
	int _N;
	DblVec _ox;
	DblVec _oy;
	DblVec _x;
	DblVec _y;
	DblVec _r;
	DblVec _m;
	IntVec _didx;
	double _score;
	double _past;
	CirclesSeparation cs;

	bool intersect(int a, int b) {
		double p = _x[a] - _x[b];
		double q = _y[a] - _y[b];
		double d = p*p + q*q;
		double c = _r[a] + _r[b];
		return d <= c*c;
	}

	double distance(int a, int b) {
		double p = _x[a] - _x[b];
		double q = _y[a] - _y[b];
		return sqrt(p*p + q*q) - (_r[a] + _r[b]);
	}

	int gx(double x) {
		int pos = (int)((x-LEFT_X) / (RIGHT_X-LEFT_X) * DRAW_WIDTH);
		return max(0, min(pos, DRAW_WIDTH));
	}

	int gy(double y) {
		int pos = (int)((y-TOP_Y) / (BOTTOM_Y-TOP_Y) * DRAW_HEIGHT);
		return max(0, min(pos, DRAW_HEIGHT));
	}

	void Run(int index);
	UINT __cdecl _Run(void);
	bool LoadFromFile(int index);

// コンストラクション
public:
	CCirclesSeparationVisDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_CIRCLESSEPARATIONVIS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void OnCancel(void);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg LRESULT OnRedraw(WPARAM wParam, LPARAM lParam);
};
