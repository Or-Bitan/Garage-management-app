
// MFCApplication2Dlg.h : header file
//

#pragma once

#include "Vehicle.h"
#include "Private_car.h"
#include"Electric_car.h"
#include<iterator>
#include <list>
// CMFCApplication2Dlg dialog
class CMFCApplication2Dlg : public CDialogEx
{
// Construction
public:
	DECLARE_SERIAL(CMFCApplication2Dlg);

	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString value1;
	CComboBox kind_of_vehicle;
	int plate;
	CEdit plate_box;
	CString name;
	CEdit owner_box;
	int Year;
	CEdit year_box;
	CString color;
	CEdit color_box;
	CString model;
	CEdit model_box;
	afx_msg void OnBnClickedAdd();
	list <Vehicle*> m;
	CString cs1;
	CEdit cs_box;
	int km;
	CEdit km_box;
	afx_msg void OnBnClickedRemove();
	int platenum;
	CEdit platenum_box;
	void Serialize(CArchive& ar);
	afx_msg void OnBnClickedsave();
	afx_msg void OnBnClickedrestore();
	int battery;
	CString tier;
	CComboBox tier_box;
	afx_msg void OnBnClickedOpenfile();
	afx_msg void OnBnClickedSavefile();
	afx_msg void OnEnChangebatterybox();
	afx_msg void OnCbnSelchangeVehicle();
	CEdit battery_box;
	afx_msg void OnEnChangeCslist();
	afx_msg void OnBnClickedGame();
	CButton game_box;
	int numberofengine;
	CEdit engine_box;
	afx_msg void OnEnChangeOwnerName();
};
