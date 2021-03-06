
// Laborator3Dlg.h : файл заголовка
//

#pragma once


// диалоговое окно CLaborator3Dlg
class CLaborator3Dlg : public CDialogEx
{
// Создание
public:
	CLaborator3Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_LABORATOR3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_nume;
	CString m_prenume;
	CString m_datan;
	BOOL m_casatorit;
	int m_ncopii;
	FILE *fang;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
