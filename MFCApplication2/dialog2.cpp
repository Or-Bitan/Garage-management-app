// dialog2.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication2.h"
#include "dialog2.h"
#include "afxdialogex.h"


// dialog2 dialog

IMPLEMENT_DYNAMIC(dialog2, CDialogEx)

dialog2::dialog2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

dialog2::~dialog2()
{
}

void dialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(dialog2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &dialog2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &dialog2::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &dialog2::OnBnClickedButton2)
END_MESSAGE_MAP()


// dialog2 message handlers


void dialog2::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL, L"open", L"https://www.elibuyukotomotiv.com/", NULL, NULL, SW_SHOWNORMAL);
}


void dialog2::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL, L"open", L"https://www.opieoils.co.uk/c-418-engine-oil-by-type.aspx", NULL, NULL, SW_SHOWNORMAL);
}


void dialog2::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	ShellExecute(NULL, L"open", L"https://www.carid.com/custom-wheels.html", NULL, NULL, SW_SHOWNORMAL);
}

