
// Laborator4Dlg.h : файл заголовка
//

#pragma once


// диалоговое окно CLaborator4Dlg
class CLaborator4Dlg : public CDialogEx
{
// Создание
public:
	CLaborator4Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_LABORATOR4_DIALOG };

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
	int m_semestrul;
	CComboBox m_curs;
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
	CString m_nume;
	CString m_prenume;
	CString m_cnp;
};
