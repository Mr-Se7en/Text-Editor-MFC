#include "afxdialogex.h"
#include <string>
#include <fstream>
#ifndef MY_HEADER
#define MY_HEADER
void stream_opener(CString filepath, std::wofstream& my_stream_out);
	
void stream_opener(CString filepath, std::ifstream& my_stream);
#endif
