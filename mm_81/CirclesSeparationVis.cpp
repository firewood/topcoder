
// CirclesSeparationVis.cpp : アプリケーションのクラス動作を定義します。
//

#include "stdafx.h"
#include "CirclesSeparationVis.h"
#include "CirclesSeparationVisDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCirclesSeparationVisApp

BEGIN_MESSAGE_MAP(CCirclesSeparationVisApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCirclesSeparationVisApp コンストラクション

CCirclesSeparationVisApp::CCirclesSeparationVisApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の CCirclesSeparationVisApp オブジェクトです。

CCirclesSeparationVisApp theApp;


// CCirclesSeparationVisApp 初期化

BOOL CCirclesSeparationVisApp::InitInstance()
{
	CWinAppEx::InitInstance();

/*
	SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));
*/

	CCirclesSeparationVisDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ダイアログが <OK> で消された時のコードを
		//  記述してください。
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ダイアログが <キャンセル> で消された時のコードを
		//  記述してください。
	}

	// ダイアログは閉じられました。アプリケーションのメッセージ ポンプを開始しないで
	//  アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}
