// Encryption_window_class.cpp : implementation file
//

#include "pch.h"
#include "File_Editor.h"
#include "afxdialogex.h"
#include "Encryption_window_class.h"
#include <string>
#include "streamopener.h"
#include "caeser's_chiper.h"


// Encryption_window_class dialog

IMPLEMENT_DYNAMIC(Encryption_window_class, CDialogEx)
const int Enc_Choice_Encrypt = 0;
const int Enc_Choice_Dencrypt = 1;
const int SV_Choice_View = 0;
const int SV_Choice_Save = 1;
Encryption_window_class::Encryption_window_class(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ENCRYPTION, pParent)
	, encrypt_decrypt_Choice(Enc_Choice_Encrypt)
	, save_view_choice_int(SV_Choice_View)
	, enc_address(_T(""))
	, key(0)
	, enc_des_address(_T(""))
	, enc_result_view(_T(""))
	, key_in(0)
{

}

Encryption_window_class::~Encryption_window_class()
{
}

void Encryption_window_class::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Encrypt_choice, encrypt_decrypt_Choice);
	DDX_Control(pDX, IDC_Encryption_des_address, des_address_boc_CTRL);
	DDX_Control(pDX, IDC_Encryption_des_browse, enc_des_browse_CTRL);
	DDX_Control(pDX, IDC_Encryption_Save, enc_save_CTRL);
	DDX_Control(pDX, IDC_STATIC_save_as_group, save_as_grouper_CTRL);
	DDX_Radio(pDX, IDC_Encryption_view, save_view_choice_int);
	DDX_Control(pDX, IDC_Encryption_View_Button, enc_view_button_CTRL);
	DDX_Text(pDX, IDC_Encryption_address, enc_address);
	DDX_Text(pDX, IDC_Enc_key, key);
	DDX_Text(pDX, IDC_Encryption_des_address, enc_des_address);
	DDX_Text(pDX, IDC_Encryption_resultBox, enc_result_view);
	DDX_Text(pDX, IDC_enc_key_in, key_in);
	DDX_Control(pDX, IDC_enc_key_in, enc_key_in_CTRL);
	DDX_Control(pDX, IDC_enc_submit_Decrypt, enc_submit_decrypt_CTRL);
	DDX_Control(pDX, IDC_STATIC_decryption_group_text, decryption_group_text);
	DDX_Control(pDX, IDC_Enc_key, enc_key_CTRL);
	DDX_Control(pDX, IDC_enc_submit_Encrypt, enc_submit_encrypt);
	DDX_Control(pDX, IDC_STATIC_encryption_group_text, encryption_group_text);
}


BEGIN_MESSAGE_MAP(Encryption_window_class, CDialogEx)
	ON_BN_CLICKED(IDC_Encryption_Save, &Encryption_window_class::OnBnClickedEncryptionSave)
	ON_BN_CLICKED(IDC_Encryption_view, &Encryption_window_class::OnBnClickedEncryptionview)
	ON_BN_CLICKED(IDC_Encryption_save_choice, &Encryption_window_class::OnBnClickedEncryptionsavechoice)
	ON_BN_CLICKED(IDC_Encryption_browse, &Encryption_window_class::OnBnClickedEncryptionbrowse)
	ON_BN_CLICKED(IDC_Encryption_des_browse, &Encryption_window_class::OnBnClickedEncryptiondesbrowse)
	ON_BN_CLICKED(IDC_Encryption_View_Button, &Encryption_window_class::OnBnClickedEncryptionViewButton)
	ON_BN_CLICKED(IDC_enc_submit_Decrypt, &Encryption_window_class::OnBnClickedencsubmitDecrypt)
	ON_BN_CLICKED(IDC_enc_submit_Encrypt, &Encryption_window_class::OnBnClickedencsubmitEncrypt)
	ON_BN_CLICKED(IDC_Encrypt_choice, &Encryption_window_class::OnBnClickedEncryptchoice)
	ON_BN_CLICKED(IDC_Decrypt_choice, &Encryption_window_class::OnBnClickedDecryptchoice)
END_MESSAGE_MAP()


// Encryption_window_class message handlers
void Encryption_window_class::ShowToggle(bool show) 
{
	int cmdShow = show ? SW_SHOW :SW_HIDE ;
	int cmdShow2 = show ? SW_HIDE : SW_SHOW;
		des_address_boc_CTRL.ShowWindow(cmdShow);
		enc_des_browse_CTRL.ShowWindow(cmdShow);
		enc_save_CTRL.ShowWindow(cmdShow);
		save_as_grouper_CTRL.ShowWindow(cmdShow);
		enc_view_button_CTRL.ShowWindow(cmdShow2);

}
void Encryption_window_class::ShowToggle2(bool show)
{
	int cmdShow = show ? SW_SHOW : SW_HIDE;
	int cmdShow2 = show ? SW_HIDE : SW_SHOW;
	enc_key_in_CTRL.ShowWindow(cmdShow);
	enc_submit_decrypt_CTRL.ShowWindow(cmdShow);
	decryption_group_text.ShowWindow(cmdShow);
	enc_key_CTRL.ShowWindow(cmdShow2);
	enc_submit_encrypt.ShowWindow(cmdShow2);
	encryption_group_text.ShowWindow(cmdShow2);
}


void Encryption_window_class::OnBnClickedEncryptionview()
{
	ShowToggle(false);
}


void Encryption_window_class::OnBnClickedEncryptionsavechoice()
{
	ShowToggle(true);
}

CString filePath_enc, filePath_des_enc, read_enc,read_enc_buf, encrypted, decrypted;
std::wstring read_enc_buf_w=L"", read_enc_w, encrypted_w, decrypted_w;
void Encryption_window_class::OnBnClickedEncryptionbrowse()
{
	std::string str = "text (*.txt)|*.txt|";
	LPCSTR pszrFilter = str.c_str();
	CFileDialog dlgFile(TRUE, _T("txt"), _T("document.txt"), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), AfxGetMainWnd());
	if (IDOK == dlgFile.DoModal()) {
		filePath_enc = dlgFile.GetPathName();
		enc_address = filePath_enc;
		CButton* pButton1 = (CButton*)GetDlgItem(IDC_Encrypt_choice);
		CButton* pButton2 = (CButton*)GetDlgItem(IDC_Decrypt_choice);
		CButton* pButton3 = (CButton*)GetDlgItem(IDC_Encryption_view);
		CButton* pButton4 = (CButton*)GetDlgItem(IDC_Encryption_save_choice);
		int nCheck1 = pButton1->GetCheck();
		int nCheck2 = pButton2->GetCheck();
		int nCheck3 = pButton3->GetCheck();
		int nCheck4 = pButton4->GetCheck();
		UpdateData(false);
		pButton1->SetCheck(nCheck1);
		pButton2->SetCheck(nCheck2);
		pButton3->SetCheck(nCheck3);
		pButton4->SetCheck(nCheck4);
	}
	std::ifstream my_stream;
	stream_opener(filePath_enc, my_stream);
	wchar_t charbuf_enc;
	while (my_stream) {
		charbuf_enc = my_stream.get();
		if (charbuf_enc == 'ÿ')
			break;
		read_enc_buf += charbuf_enc;
		read_enc_buf_w += charbuf_enc;
	}
	read_enc = read_enc_buf;
	read_enc_w = read_enc_buf_w;
	read_enc_buf = "";
	read_enc_buf_w =L"";
	my_stream.close();
	
}




void Encryption_window_class::OnBnClickedEncryptiondesbrowse()
{
	std::string str_des = "text (*.txt)|*.txt|";
	LPCSTR pszrFilter = str_des.c_str();
	CFileDialog dlgFile_des(FALSE, _T("txt"), _T("document.txt"), OFN_HIDEREADONLY, _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), AfxGetMainWnd());
	if (IDOK == dlgFile_des.DoModal()) {
		filePath_des_enc = dlgFile_des.GetPathName();
		enc_des_address = filePath_des_enc;
		save_view_choice_int = { 1 };
		CButton* pButton1 = (CButton*)GetDlgItem(IDC_Encrypt_choice);
		CButton* pButton2 = (CButton*)GetDlgItem(IDC_Decrypt_choice);
		CButton* pButton3 = (CButton*)GetDlgItem(IDC_Encryption_view);
		CButton* pButton4 = (CButton*)GetDlgItem(IDC_Encryption_save_choice);
		int nCheck1 = pButton1->GetCheck();
		int nCheck2 = pButton2->GetCheck();
		int nCheck3 = pButton3->GetCheck();
		int nCheck4 = pButton4->GetCheck();
		UpdateData(false);
		pButton1->SetCheck(nCheck1);
		pButton2->SetCheck(nCheck2);
		pButton3->SetCheck(nCheck3);
		pButton4->SetCheck(nCheck4);


	}
}

void Encryption_window_class::OnBnClickedEncryptionSave()//button
{
	if(Enc_Choice_Encrypt==encrypt_decrypt_Choice){
		std::wofstream my_stream_out;
		stream_opener(filePath_des_enc, my_stream_out);
		my_stream_out << encrypted_w;
		my_stream_out.close();
		MessageBox(L"done");
	}
	if (Enc_Choice_Dencrypt == encrypt_decrypt_Choice) {
		std::wofstream my_stream_out;
		stream_opener(filePath_des_enc, my_stream_out);
		my_stream_out << decrypted_w;
		my_stream_out.close();
		MessageBox(L"done");
	}
}
void Encryption_window_class::OnBnClickedEncryptionViewButton()
{
	if (Enc_Choice_Encrypt == encrypt_decrypt_Choice) {
		enc_result_view = encrypted;
		CButton* pButton1 = (CButton*)GetDlgItem(IDC_Encrypt_choice);
		CButton* pButton2 = (CButton*)GetDlgItem(IDC_Decrypt_choice);
		CButton* pButton3 = (CButton*)GetDlgItem(IDC_Encryption_view);
		CButton* pButton4 = (CButton*)GetDlgItem(IDC_Encryption_save_choice);
		int nCheck1 = pButton1->GetCheck();
		int nCheck2 = pButton2->GetCheck();
		int nCheck3 = pButton3->GetCheck();
		int nCheck4 = pButton4->GetCheck();
		UpdateData(false);
		pButton1->SetCheck(nCheck1);
		pButton2->SetCheck(nCheck2);
		pButton3->SetCheck(nCheck3);
		pButton4->SetCheck(nCheck4);
	}
	if (Enc_Choice_Dencrypt == encrypt_decrypt_Choice) {
		CButton* pButton1 = (CButton*)GetDlgItem(IDC_Encrypt_choice);
		CButton* pButton2 = (CButton*)GetDlgItem(IDC_Decrypt_choice);
		CButton* pButton3 = (CButton*)GetDlgItem(IDC_Encryption_view);
		CButton* pButton4 = (CButton*)GetDlgItem(IDC_Encryption_save_choice);
		int nCheck1 = pButton1->GetCheck();
		int nCheck2 = pButton2->GetCheck();
		int nCheck3 = pButton3->GetCheck();
		int nCheck4 = pButton4->GetCheck();
		UpdateData(false);
		pButton1->SetCheck(nCheck1);
		pButton2->SetCheck(nCheck2);
		pButton3->SetCheck(nCheck3);
		pButton4->SetCheck(nCheck4);

	}
}

void Encryption_window_class::OnBnClickedencsubmitDecrypt()
{
	encrypt_decrypt_Choice = Enc_Choice_Dencrypt;
	CButton* pButton1 = (CButton*)GetDlgItem(IDC_Encrypt_choice);
	CButton* pButton2 = (CButton*)GetDlgItem(IDC_Decrypt_choice);
	CButton* pButton3 = (CButton*)GetDlgItem(IDC_Encryption_view);
	CButton* pButton4 = (CButton*)GetDlgItem(IDC_Encryption_save_choice);
	int nCheck1 = pButton1->GetCheck();
	int nCheck2 = pButton2->GetCheck();
	int nCheck3 = pButton3->GetCheck();
	int nCheck4 = pButton4->GetCheck();
	UpdateData(true);
	pButton1->SetCheck(nCheck1);
	pButton2->SetCheck(nCheck2);
	pButton3->SetCheck(nCheck3);
	pButton4->SetCheck(nCheck4);
		if (key_in) {
			decrypted = decrypt(read_enc, key_in);
			decrypted_w = decrypt(read_enc_w, key_in);
		}
		else {
			MessageBox(L"Please enter the encryption key");
		}
}


void Encryption_window_class::OnBnClickedencsubmitEncrypt()
{
	encrypt_decrypt_Choice = Enc_Choice_Encrypt;
	key = key_gen();
	CButton* pButton1 = (CButton*)GetDlgItem(IDC_Encrypt_choice);
	CButton* pButton2 = (CButton*)GetDlgItem(IDC_Decrypt_choice);
	CButton* pButton3 = (CButton*)GetDlgItem(IDC_Encryption_view);
	CButton* pButton4 = (CButton*)GetDlgItem(IDC_Encryption_save_choice);
	int nCheck1 = pButton1->GetCheck();
	int nCheck2 = pButton2->GetCheck();
	int nCheck3 = pButton3->GetCheck();
	int nCheck4 = pButton4->GetCheck();
	UpdateData(false);
	pButton1->SetCheck(nCheck1);
	pButton2->SetCheck(nCheck2);
	pButton3->SetCheck(nCheck3);
	pButton4->SetCheck(nCheck4);
		encrypted = encrypt(read_enc, key);
		encrypted_w = encrypt(read_enc_w, key);
}


void Encryption_window_class::OnBnClickedEncryptchoice()
{
	ShowToggle2(false);
	encrypt_decrypt_Choice =Enc_Choice_Dencrypt ;
}


void Encryption_window_class::OnBnClickedDecryptchoice()
{
	ShowToggle2(true);
	encrypt_decrypt_Choice = Enc_Choice_Encrypt;
}
