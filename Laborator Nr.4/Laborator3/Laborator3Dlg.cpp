
// Laborator3Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Laborator3.h"
#include "Laborator3Dlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()




CLaborator3Dlg::CLaborator3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLaborator3Dlg::IDD, pParent)
	, m_nume(_T(""))
	, m_prenume(_T(""))
	, m_datan(_T(""))
	, m_casatorit(FALSE)
	, m_ncopii(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ncopii = 0;
}

void CLaborator3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Nume, m_nume);
	DDX_Text(pDX, IDC_PRENUME, m_prenume);
	DDX_Text(pDX, IDC_DATAN, m_datan);
	DDX_Check(pDX, IDC_CASATORIT, m_casatorit);
	//  DDX_Text(pDX, IDC_NCOPII, m_ncopii);
	DDX_Text(pDX, IDC_NCOPII, m_ncopii);
}

BEGIN_MESSAGE_MAP(CLaborator3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CLaborator3Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CLaborator3Dlg::OnBnClickedOk)
END_MESSAGE_MAP()



BOOL CLaborator3Dlg::OnInitDialog()
{
	fang = fopen("angajat.txt","a");
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	return TRUE; 
}

void CLaborator3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLaborator3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR CLaborator3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLaborator3Dlg::OnBnClickedCancel()
{
	// TODO: ???????? ???? ??? ??????????? ???????????
	fclose(fang);
	CDialogEx::OnCancel();
}


void CLaborator3Dlg::OnBnClickedOk()
{
	// TODO: Add extra validation here 
	UpdateData(); // Transfer din controale in variabile 

	/*Conversia in sir de carcatere*/
	CT2CA pszConvertedAnsiString1 (m_nume);
	std::string sm_nume (pszConvertedAnsiString1);
	CT2CA pszConvertedAnsiString2 (m_prenume);
	std::string sm_prenume (pszConvertedAnsiString2);
	CT2CA pszConvertedAnsiString3 (m_datan);
	std::string sm_datan (pszConvertedAnsiString3);
	fprintf(fang, "%s \t %s \t %s \t %1d \t %d\n", sm_nume.c_str(), sm_prenume.c_str(), sm_datan.c_str(), m_casatorit, m_ncopii); 
	// Se golesc campurile formularului: 
	m_nume = ""; 
	m_prenume = ""; 
	m_datan = ""; 
	m_casatorit = FALSE; 
	m_ncopii = 0; 
	UpdateData(FALSE); 
	GetDlgItem(IDC_Nume)->SetFocus(); // Prima caseta de text primeste con
	// CDialog::OnOK(); // Se anuleaza pentru a nu iesi din aplicatie. 
}
