#pragma once


// CPage3Dlg 대화 상자

class CPage3Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPage3Dlg)

public:
	CPage3Dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPage3Dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
