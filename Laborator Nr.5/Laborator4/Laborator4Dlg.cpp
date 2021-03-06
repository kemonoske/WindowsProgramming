
// Laborator4Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Laborator4.h"
#include "Laborator4Dlg.h"
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
	virtual void DoDataExchange(CDataExchange* pDX);    

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



CLaborator4Dlg::CLaborator4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLaborator4Dlg::IDD, pParent)
	, m_nume(_T(""))
	, m_prenume(_T(""))
	, m_cnp(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_semestrul = 0;
}

void CLaborator4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_SEMESTRUL, m_semestrul);
	DDX_Control(pDX, IDC_COMBO1, m_curs);
	DDX_Text(pDX, IDC_EDIT1, m_nume);
	DDX_Text(pDX, IDC_EDIT2, m_prenume);
	DDX_Text(pDX, IDC_EDIT3, m_cnp);
}

BEGIN_MESSAGE_MAP(CLaborator4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CLaborator4Dlg::OnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CLaborator4Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


BOOL CLaborator4Dlg::OnInitDialog()
{
	//UpdateData(FALSE);
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

	m_semestrul = 0;
	m_curs.AddString(L"(alegeti cursul)"); 
	m_curs.AddString(L"Bazele utilizarii"); 
	m_curs.AddString(L"Bazele programarii"); 
	m_curs.AddString(L"Baze de date"); 
	m_curs.AddString(L"Situri siaplicatii pentru Web"); 
	m_curs.SelectString(-1, L"(alegeti cursul)"); 
	return TRUE;  
}

void CLaborator4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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


void CLaborator4Dlg::OnPaint()
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

HCURSOR CLaborator4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*Schimbarea valorii COMBO BOX*/
void CLaborator4Dlg::OnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here 
	if(m_curs.GetCurSel() == 1) 
		{ 
			UpdateData(); 
			m_semestrul=1; // Se ruleaza in sem. 2 
			UpdateData(FALSE); 
			GetDlgItem(IDC_SEMESTRUL)->EnableWindow(FALSE); 
			GetDlgItem(IDC_SEMESTRUL2)->EnableWindow(FALSE); 
		} 
	else 
		{ 
			GetDlgItem(IDC_SEMESTRUL)->EnableWindow(); 
			GetDlgItem(IDC_SEMESTRUL2)->EnableWindow(); 
		} 
}

/*SALVAREA AICI*/
void CLaborator4Dlg::OnBnClickedOk()
{
	// TODO: Add extra validation here 
	UpdateData(); // Transfer din controale in variabile 
	wchar_t nume_curs[100]; 
	// Gasesc linia selectata 
	int i = m_curs.GetCurSel(); 
	FILE *ffisa = fopen("fisa.txt","a");
	m_curs.GetLBText( i, (LPTSTR)nume_curs ); 
	CT2CA pszConvertedAnsiString1 (m_nume);
	std::string sm_nume (pszConvertedAnsiString1);
	CT2CA pszConvertedAnsiString2 (m_prenume);
	std::string sm_prenume (pszConvertedAnsiString2);
	CT2CA pszConvertedAnsiString3 (m_cnp);
	std::string sm_cnp (pszConvertedAnsiString3);
	CT2CA pszConvertedAnsiString4 (nume_curs);
	std::string sm_curs (pszConvertedAnsiString4);
	fprintf(ffisa, "%s \t %s \t %s\t %s \n", sm_nume.c_str(), sm_prenume.c_str(), sm_cnp.c_str(), sm_curs.c_str()); 
	fclose(ffisa); 
	CDialog::OnOK(); 
}
