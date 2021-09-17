#pragma once


// dialog2 dialog

class dialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(dialog2)

public:
	dialog2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~dialog2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
