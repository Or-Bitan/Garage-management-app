
// MFCApplication2Dlg.cpp : implementation file
//

#include "pch.h"
#include "Private_car.h"
#include "Vehicle.h"
#include"Electric_car.h"
#include "Bus.h"
#include "framework.h"
#include "dialog2.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "Plane.h"
#include <typeinfo>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
IMPLEMENT_SERIAL(CMFCApplication2Dlg, CDialogEx, VERSIONABLE_SCHEMA | 1)

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg dialog



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, value1(_T(""))
	, plate(0)
	, name(_T(""))
	, Year(0)
	, color(_T(""))
	, model(_T(""))
	, cs1(_T(""))
	, km(0)
	, platenum(0)
	, battery(0)
	, tier(_T(""))
	, numberofengine(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_Vehicle, value1);
	DDX_Control(pDX, IDC_Vehicle, kind_of_vehicle);
	DDX_Text(pDX, IDC_plate, plate);
	DDX_Control(pDX, IDC_plate, plate_box);
	DDX_Text(pDX, IDC_Owner_Name, name);
	DDX_Control(pDX, IDC_Owner_Name, owner_box);
	DDX_Text(pDX, IDC_Year, Year);
	/*DDV_MinMaxInt(pDX, Year, 1960, 2021);*/
	DDX_Control(pDX, IDC_Year, year_box);
	DDX_Text(pDX, IDC_Color, color);
	DDX_Control(pDX, IDC_Color, color_box);
	DDX_Text(pDX, IDC_Model, model);
	DDX_Control(pDX, IDC_Model, model_box);
	DDX_Text(pDX, IDC_CSlist, cs1);
	DDX_Control(pDX, IDC_CSlist, cs_box);
	DDX_Text(pDX,
		IDC_KM, km);
	DDX_Control(pDX, IDC_KM, km_box);
	DDX_Text(pDX, IDC_plate_num, platenum);
	DDX_Control(pDX, IDC_plate_num, platenum_box);
	DDX_Text(pDX, IDC_battery_box, battery);
	//DDV_MinMaxInt(pDX, battery, 0, 10);
	DDX_CBString(pDX, IDC_tier, tier);
	DDX_Control(pDX, IDC_tier, tier_box);
	DDX_Control(pDX, IDC_battery_box, battery_box);
	DDX_Control(pDX, IDC_Game, game_box);
	DDX_Text(pDX, IDC_EDIT1, numberofengine);
	DDX_Control(pDX, IDC_EDIT1, engine_box);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CMFCApplication2Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_Remove, &CMFCApplication2Dlg::OnBnClickedRemove)
	ON_BN_CLICKED(IDC_save, &CMFCApplication2Dlg::OnBnClickedsave)
	ON_BN_CLICKED(IDC_restore, &CMFCApplication2Dlg::OnBnClickedrestore)
	ON_BN_CLICKED(IDC_OpenFILE, &CMFCApplication2Dlg::OnBnClickedOpenfile)
	ON_BN_CLICKED(IDC_SaveFile, &CMFCApplication2Dlg::OnBnClickedSavefile)
	ON_EN_CHANGE(IDC_battery_box, &CMFCApplication2Dlg::OnEnChangebatterybox)
	ON_CBN_SELCHANGE(IDC_Vehicle, &CMFCApplication2Dlg::OnCbnSelchangeVehicle)
	ON_EN_CHANGE(IDC_CSlist, &CMFCApplication2Dlg::OnEnChangeCslist)
	ON_BN_CLICKED(IDC_Game, &CMFCApplication2Dlg::OnBnClickedGame)
	ON_EN_CHANGE(IDC_Owner_Name, &CMFCApplication2Dlg::OnEnChangeOwnerName)
END_MESSAGE_MAP()


// CMFCApplication2Dlg message handlers

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedAdd()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	 if (plate == 0)
	{
	AfxMessageBox(_T("Enter plate number"));
	return;
	}
	 else if (name.IsEmpty())
	 {
		 AfxMessageBox(_T("Enter owner name"));
		 return;
	 }
	else if (Year < 1960 || Year>2021)
	{
		AfxMessageBox(_T("Enter year betwen 1960-2021"));
		return;
	}
	else if (color.IsEmpty())
	{
		AfxMessageBox(_T("Enter color"));
		return;
	}
	else if (model.IsEmpty())
	{
		AfxMessageBox(_T("Enter model"));
		return;
	}
	

	if (value1 == "Car" && Year >= 1960 && Year <= 2021 && color.IsEmpty() == false && name.IsEmpty() == false && name.IsEmpty() == false && plate!=0)
	{
		if (km == 0)
		{
			AfxMessageBox(_T("Enter km"));
			return;
		}
		CString type = CString("car");
	
		PrivateCar* dyn = new PrivateCar(name, km, Year, color, plate, model, type);
		m.push_back(dyn);
		cs1 += dyn->ToString().c_str();
		cs1 += "\r\n";
	}
	else if (value1 == "Electric car" && Year >= 1960 && Year <= 2021 && color.IsEmpty() == false && name.IsEmpty() == false && name.IsEmpty() == false && plate != 0)
	{
		if(battery <= 0 || battery > 10)
		{
			AfxMessageBox(_T("Enter correct battery age"));
			return;
		}
		if (km == 0)
		{
			AfxMessageBox(_T("Enter km"));
			return;
		}
		CString type = CString("Electric Car");

		PrivateCar* dyn = new Electric_car(name, km, Year, color, plate, model, battery, type);
		m.push_back(dyn);
		cs1 += dyn->ToString().c_str();
		cs1 += "\r\n";
	}
	else if (value1 == "Bus" && Year >= 1960 && Year <= 2021 && color.IsEmpty() == false && name.IsEmpty() == false && name.IsEmpty() == false && plate != 0 )
	{
		if(tier.IsEmpty())
		{
			AfxMessageBox(_T("is tier replace in the last year?"));
			return;
		}
		if (km == 0)
		{
			AfxMessageBox(_T("Enter km"));
			return;
		}
		CString type = CString("Bus");

		Vehicle* dyn = new Bus(name, km, Year, color, plate, model, type, tier);
		m.push_back(dyn);
		cs1 += dyn->ToString().c_str();
		cs1 += "\r\n";
	}
	else if (value1 == "Plane" && Year >= 1960 && Year <= 2021 && color.IsEmpty() == false && name.IsEmpty() == false && name.IsEmpty() == false && plate != 0)
	{
		if (numberofengine==0)
		{
			AfxMessageBox(_T("Enter number of engine"));
			return;
		}
		CString type = CString("Plane");
		/*Plane(int engines, int year, CString color, int plate_number, CString Model, CString type);*/

		Vehicle* dyn = new Plane(numberofengine,name, Year, color, plate, model,type);
		m.push_back(dyn);
		cs1 += dyn->ToString().c_str();
		cs1 += "\r\n";
	}
	else {
		AfxMessageBox(_T("Enter All fields"));
		return;
	}
	Year = 0;
	plate = 0;
	km = 0;
	kind_of_vehicle.SetCurSel(-1);
	value1.Empty();
	tier_box.SetCurSel(-1);
	tier.Empty();
	name.Empty();
	color.Empty();
	model.Empty();
	battery = 0;
	UpdateData(false);

}
void CMFCApplication2Dlg::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	int size = m.size();
	if (ar.IsStoring())
		ar << m.size();
	else
		ar >> size;

	while (size)
	{
		if (ar.IsStoring())
		{
			if (m.front()->type == "car")
			{
				/*(CString owner_name, int km, int year, CString color, int plate_number, CString Model, CString type)*/
				Vehicle* v1 = new PrivateCar();
				v1 = m.front();
				ar << m.front()->type << m.front()->plate_number << v1->year << static_cast<PrivateCar*>(v1)->owner_name << static_cast<PrivateCar*>(v1)->km << v1->color << v1->Model;
		    }
			else if (m.front()->type == "Electric car")
			{
				Vehicle* v1 = new Electric_car();
				v1 = m.front();
				ar << m.front()->type << m.front()->plate_number << v1->year << static_cast<PrivateCar*>(v1)->owner_name << static_cast<PrivateCar*>(v1)->km << v1->color << v1->Model << static_cast<Electric_car*>(v1)->batteryAge;
			}
			else if (m.front()->type == "Bus")
			{
				Vehicle* v1 = new Bus();
				v1 = m.front();
				ar << m.front()->type << m.front()->plate_number << v1->year << static_cast<PrivateCar*>(v1)->owner_name << static_cast<PrivateCar*>(v1)->km << v1->color << v1->Model << static_cast<Bus*>(v1)->tier;
			}
			else if (m.front()->type == "Plane")
			{
				Vehicle* v1 = new Plane();
				v1 = m.front();
				ar << m.front()->type << m.front()->plate_number << v1->year  << v1->color << v1->Model << static_cast<Plane*>(v1)->Engines << static_cast<Plane*>(v1)->owner_name;
			}
			m.pop_front();
		}
		else
		{
			

				CString type;
				ar >> type;
					if (type == "car")
					{
				Vehicle* v1 = new PrivateCar();
				v1->type = "car";
				ar >>  v1->plate_number >> v1->year >> static_cast<PrivateCar*>(v1)->owner_name >> static_cast<PrivateCar*>(v1)->km >> v1->color >> v1->Model;
				m.push_back(v1);
					}
					else if (type=="Electric car")
					{
						Vehicle* v1 = new Electric_car();
						v1->type = "Electric car";
						ar >> v1->plate_number >> v1->year >> static_cast<PrivateCar*>(v1)->owner_name >>static_cast<PrivateCar*>(v1)->km >> v1->color >> v1->Model >>static_cast<Electric_car*>(v1)->batteryAge;
					/*	 ar >> v1->plate_number >> v1->year >> static_cast<Electric_car*>(v1)->batteryAge;*/
						 m.push_back(v1);
					}
					else if (type == "Bus")
					{
						Vehicle* v1 = new Bus();
						v1->type = "Bus";
						ar >> v1->plate_number >> v1->year >> static_cast<PrivateCar*>(v1)->owner_name >> static_cast<PrivateCar*>(v1)->km >> v1->color >> v1->Model >> static_cast<Bus*>(v1)->tier;
						/*	 ar >> v1->plate_number >> v1->year >> static_cast<Electric_car*>(v1)->batteryAge;*/
						m.push_back(v1);
					}
					else if (type == "Plane")
					{
						Vehicle* v1 = new Plane();
						v1->type = "Plane";
						ar >> v1->plate_number >> v1->year  >>  v1->color >> v1->Model >> static_cast<Plane*>(v1)->Engines >> static_cast<Plane*>(v1)->owner_name;
						/*	 ar >> v1->plate_number >> v1->year >> static_cast<Electric_car*>(v1)->batteryAge;*/
						m.push_back(v1);
					}


				/*	ar << m.front()->type << m.front()->plate_number << v1->year << v1->color << v1->Model << static_cast<Plane*>(v1)->Engines;*/
		/*	else
			{
				
				ar >> m.front()->type >> m.front()->plate_number >> v1->year >> static_cast<Electric_car*>(v1)->km;
				m.push_back(v1);
			}*/
	
			/*
			{
				Vehicle* v2 = new Vehicle();
			
				ar >> v2->plate_number >> v2->year;
				m.push_back(v2);
			}*/
		}
		size--;
	}

	
}

void CMFCApplication2Dlg::OnBnClickedRemove()
{
	// TODO: Add your control notification handler code here

	list <Vehicle*>::iterator it;
	UpdateData(true);
	it = m.begin();

	int flag = 0;
	while (it != m.end())
	{

		Vehicle* remove_car = *it;
		if (remove_car->get_plate_number() == platenum)
		{

			m.erase(it);
			cs1.Empty();
			flag = 1;
			break;

		}
		/*
		 if (it == m.end())
			break;*/
		it++;
	}
	int pos = 0;
	if (!m.empty() && flag == 1)
	{
		it = m.begin();
		while (pos != m.size())
		{
			Vehicle* v = *it;
			cs1 += v->ToString().c_str();
			cs1 += "\r\n";
			it++;
			pos++;

		}
	}
	platenum = 0;
	UpdateData(false);
	if (!flag)
		AfxMessageBox(_T("plate number didnt exsist!"));
}



void CMFCApplication2Dlg::OnBnClickedsave()
{
	// TODO: Add your control notification handler code here




	UpdateData(true);
	CFile file;
	file.Open(L"EmployeeInfo.hse", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);

	CMFCApplication2Dlg b;

	/*b.m.push_front(m.front());*/
	while (m.size())
	{
		if (m.front()->type == "car")
		{
			Vehicle* v = new PrivateCar();
			v = m.front();
			b.m.push_back(v);
			m.pop_front();
		}
		else if (m.front()->type == "Electric Car")
		{
			Vehicle* v2 = new Electric_car();
				v2 = m.front();
			b.m.push_back(v2);
			m.pop_front();
		}
		else if (m.front()->type == "Bus")
		{
			Vehicle* v = new Bus();
			v = m.front();
			b.m.push_back(v);
			m.pop_front();
		}
		else if (m.front()->type == "Plane")
		{
			Vehicle* v = new Plane();
			v = m.front();
			b.m.push_back(v);
			m.pop_front();
		}

	}
	b.Serialize(ar);
	ar.Close();
	AfxMessageBox(_T("Saved!"));
	/*Vehicle v2 = **it;
	v2.Serialize(ar);
	*/


	/*Vehicle *v1=*it;
	v1->Serialize(ar);*/

	//while (it != m.end())
	//{

	//	Vehicle* employee = *it;
	//
	//	employee->Serialize(ar);
	//	/*
	//	 if (it == m.end())
	//		break;*/
	//	it++;
	//}


	/*employee.set_plate_number(plate);
	employee.owner_name = CString("banna");

	ar.Close();*/




}


void CMFCApplication2Dlg::OnBnClickedrestore()
{
	// TODO: Add your control notification handler code here

	list <Vehicle*>::iterator it;
	CFile file;

	file.Open(L"EmployeeInfo.hse", CFile::modeRead);
	CArchive ar(&file, CArchive::load);

	/*Vehicle *v1=*it;
	v1->Serialize(ar);*/



	CMFCApplication2Dlg b;
	b.Serialize(ar);
	
	/*		cs1 += b.m.front()->ToString().c_str();*/
	it = b.m.begin();
	while (it != b.m.end())
	{
		CString car = CString("car");
		//(CString owner_name, int km, int year, CString color, int plate_number, CString Model, int batteryage, CString type)
		if (b.m.front()->type == "car")
		{
			Vehicle* v2 = new PrivateCar();
			v2 = *it;
			m.push_back(v2);
			cs1 += v2->ToString().c_str();
			cs1 += "\r\n";
		}
	
		else if (b.m.front()->type == "Electric_car")
		{
			Vehicle* v2 = new Electric_car();
			v2 = *it;
			m.push_back(v2);
			cs1 += v2->ToString().c_str();
			cs1 += "\r\n";
		}
		else if (b.m.front()->type == "Bus")
		{
			Vehicle* v2 = new Bus();
			v2 = *it;
			m.push_back(v2);
			cs1 += v2->ToString().c_str();
			cs1 += "\r\n";
		}
		else if (b.m.front()->type == "Plane")
		{
			Vehicle* v2 = new Plane();
			v2 = *it;
			m.push_back(v2);
			cs1 += v2->ToString().c_str();
			cs1 += "\r\n";
		}

		
			it++;
		
	}

	ar.Close();


	//		//value1 = CString("Car");
	//		//cs1 = employee.ToString().c_str();
	//		file.Close();
	//
			UpdateData(false);
}



void CMFCApplication2Dlg::OnBnClickedOpenfile()
{
	// TODO: Add your control notification handler code here

	LPCTSTR pszFilter = _T("Text(*.txt)|*.txt||");
	CFileDialog dlgFile(true,_T("text"),NULL,OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,pszFilter,AfxGetMainWnd());

	if (IDOK == dlgFile.DoModal())
	{
		CStdioFile f;
		if (f.Open(dlgFile.GetPathName(), CFile::modeRead | CFile::shareDenyNone | CFile::typeText))
		{
			CString strLine;
			while (f.ReadString(strLine))
			{
			
				cs1 += strLine;
				cs1 += "\r\n";
				
			}
		}
		UpdateData(false);
	}

}


void CMFCApplication2Dlg::OnBnClickedSavefile()
{
	// TODO: Add your control notification handler code here

	LPCTSTR pszFilter = _T("Text(*.txt)|*.txt||");
	CFileDialog dlgFile(false, _T("text"), _T("Untitled.txt"), OFN_OVERWRITEPROMPT , pszFilter, AfxGetMainWnd());

	if(IDOK==dlgFile.DoModal())
	{ 
		CStdioFile f;
		if (f.Open(dlgFile.GetPathName(), CFile::modeCreate | CFile::modeWrite | CFile::typeText))
		{
			UpdateData();
			CString strLine;

			f.WriteString(cs1);
	
		}
	}
		
}


void CMFCApplication2Dlg::OnEnChangebatterybox()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCApplication2Dlg::OnCbnSelchangeVehicle()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if (value1 == "Car" || value1 == "Electric car" || value1 == "Plane")
	{
		tier_box.EnableWindow(FALSE);
	}
	else
		tier_box.EnableWindow(true);
	if (value1 =="Electric car")
	{
		battery_box.EnableWindow(true);
	}
	else 
		battery_box.EnableWindow(false);
	if (value1 == "Plane")
	{
		engine_box.EnableWindow(true);
		km_box.EnableWindow(false);
		/*owner_box.EnableWindow(false);*/
	}
	else
	{
		engine_box.EnableWindow(false);
		km_box.EnableWindow(true);
		owner_box.EnableWindow(true);
	}

}


void CMFCApplication2Dlg::OnEnChangeCslist()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCApplication2Dlg::OnBnClickedGame()
{
	// TODO: Add your control notification handler code here

	dialog2 dlg;
	dlg.DoModal();
	
	
}

void CMFCApplication2Dlg::OnEnChangeOwnerName()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
