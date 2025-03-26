
// bymchicken_v10Dlg.h: 헤더 파일
//

#include "CPage1Dlg.h"
#include "CPage2Dlg.h"
#include "CPage3Dlg.h"

#pragma once


// Cbymchickenv10Dlg 대화 상자
class Cbymchickenv10Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cbymchickenv10Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BYMCHICKEN_V10_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.

private:
	CPage1Dlg m_page1;
	CPage2Dlg m_page2;
	CPage3Dlg m_page3;
	CTabCtrl* m_tab;

protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
