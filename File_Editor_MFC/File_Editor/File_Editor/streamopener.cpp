#include"pch.h"
#include "streamopener.h"
void stream_opener(CString filepath, std::wofstream& my_stream_out) {
	try {
		my_stream_out.open(filepath, std::ios::binary);
		if (!my_stream_out) {
			throw 10;
		}
	}
	catch (int x) {
		int msgboxID = MessageBox(NULL, (LPCWSTR)L"failed to open stream try again", NULL, NULL);
	}
}
void stream_opener(CString filepath, std::ifstream& my_stream) {
	try {
		my_stream.open(filepath, std::ios::binary);
		if (!my_stream.good()) {
			throw 10;
		}
	}
	catch (int x) {
		int msgboxID = MessageBox(NULL, (LPCWSTR)L"failed to open file try again", NULL, NULL);
	}
}