
// File_EditorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "File_Editor.h"
#include "File_EditorDlg.h"
#include "afxdialogex.h"
#include"open_window_class.h"
#include"copy_window_class.h"
#include "Encryption_window_class.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CFileEditorDlg dialog



CFileEditorDlg::CFileEditorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FILE_EDITOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFileEditorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CFileEditorDlg::OnBnClickedCancel)
	ON_BN_CLICKED(encryption, &CFileEditorDlg::OnBnClickedencryption)
	ON_BN_CLICKED(IDC_Open, &CFileEditorDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_Copy, &CFileEditorDlg::OnBnClickedCopy)
	ON_BN_CLICKED(IDC_Exit, &CFileEditorDlg::OnBnClickedExit)
END_MESSAGE_MAP()


// CFileEditorDlg message handlers

BOOL CFileEditorDlg::OnInitDialog()
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
	
	//open_window_class.create(IDD_OPEN_dlg, this);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFileEditorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileEditorDlg::OnPaint()
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
HCURSOR CFileEditorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileEditorDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


//void CFileEditorDlg::OnBnClickedButton4()//exit
//{
//
//}
//
//
//void CFileEditorDlg::OnBnClickedButton2()//open
//{
//	
//}


//void CFileEditorDlg::OnBnClickedButton3()//copy
//{
	




void CFileEditorDlg::OnBnClickedencryption()
{
	Encryption_window_class encrypt;
	encrypt.DoModal();
}


void CFileEditorDlg::OnBnClickedOpen()
{
	open_window_class open;
	open.DoModal();
}


void CFileEditorDlg::OnBnClickedCopy()
{
	copy_window_class copy;
	copy.DoModal();
}


void CFileEditorDlg::OnBnClickedExit()
{
	exit(0);
}
