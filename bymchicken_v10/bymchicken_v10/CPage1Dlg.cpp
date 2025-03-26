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
END_MESSAGE_MAP()


// CPage1Dlg 메시지 처리기
