﻿#pragma once


// CPage1Dlg 대화 상자

class CPage1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPage1Dlg)

public:
	CPage1Dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPage1Dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
};
