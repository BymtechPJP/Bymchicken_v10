﻿
// bymchicken_v10Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "bymchicken_v10.h"
#include "bymchicken_v10Dlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbymchickenv10Dlg 대화 상자



Cbymchickenv10Dlg::Cbymchickenv10Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BYMCHICKEN_V10_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cbymchickenv10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cbymchickenv10Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &Cbymchickenv10Dlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// Cbymchickenv10Dlg 메시지 처리기

BOOL Cbymchickenv10Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	// 윈도우 크기 설정
	CRect dlgRect;
	dlgRect.left = 0;
	dlgRect.top = 0;
	dlgRect.right = dlgRect.left + 1024;  // 너비 px 설정
	dlgRect.bottom = dlgRect.top + 768;  // 높이 px 설정

	MoveWindow(&dlgRect);

	// 탭 초기화
	m_tab = (CTabCtrl*)GetDlgItem(IDC_TAB1);
	m_tab->MoveWindow(112, 40, 800, 600);
	m_tab->InsertItem(0, _T("수동"));
	m_tab->InsertItem(1, _T("자동"));
	m_tab->InsertItem(2, _T("설정"));

	// 위치 잡기
	CRect tabRect, itemRect;
	m_tab->GetWindowRect(&tabRect);
	ScreenToClient(&tabRect);

	m_tab->GetItemRect(0, &itemRect); // 첫 번째 탭의 높이 계산
	tabRect.top += itemRect.Height() + 5;
	tabRect.left += 4;
	tabRect.right -= 4;
	tabRect.bottom -= 4;

	m_page1.Create(IDD_DIALOG1, this);
	m_page2.Create(IDD_DIALOG2, this);
	m_page3.Create(IDD_DIALOG3, this);

	m_page1.MoveWindow(&tabRect);
	m_page2.MoveWindow(&tabRect);
	m_page3.MoveWindow(&tabRect);

	// 초기 페이지만 보이게
	m_page1.ShowWindow(SW_SHOW);
	m_page1.SetDlgItemText(IDC_EDIT1, _T("수동 탭이 눌렸습니다"));
	m_page2.ShowWindow(SW_HIDE);
	m_page3.ShowWindow(SW_HIDE);



	m_tab->Invalidate();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cbymchickenv10Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cbymchickenv10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cbymchickenv10Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_tab->GetCurSel();

	// 모두 숨기고 선택된 것만 보이게
	m_page1.ShowWindow(SW_HIDE);
	m_page2.ShowWindow(SW_HIDE);
	m_page3.ShowWindow(SW_HIDE);

	switch (sel)
	{
		case 0:
		{
			m_page1.ShowWindow(SW_SHOW);
			m_page1.SetDlgItemText(IDC_EDIT1, _T("수동 탭이 눌렸습니다"));
			break;
		}
		case 1:
		{
			m_page2.ShowWindow(SW_SHOW);
			m_page2.SetDlgItemText(IDC_EDIT1, _T("자동 탭이 눌렸습니다"));
			break;
		}
		case 2:
		{
			m_page3.ShowWindow(SW_SHOW);
			m_page3.SetDlgItemText(IDC_EDIT1, _T("설정 탭이 눌렸습니다"));
			break;
		}
	}

	*pResult = 0;
}
