
//
// CirclesSeparationVis.h : Visualizer
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル
#include "CirclesSeparation.h"

//

class CCirclesSeparationVisApp : public CWinAppEx
{
public:
	CCirclesSeparationVisApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCirclesSeparationVisApp theApp;

