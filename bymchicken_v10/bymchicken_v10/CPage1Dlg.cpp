// CPage1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "bymchicken_v10.h"
#include "CPage1Dlg.h"
#include "afxdialogex.h"


// CPage1Dlg 대화 상자

IMPLEMENT_DYNAMIC(CPage1Dlg, CDialogEx)

CPage1Dlg::CPage1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CPage1Dlg::~CPage1Dlg()
{
}

void CPage1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage1Dlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CPage1Dlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CPage1Dlg 메시지 처리기


void CPage1Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
