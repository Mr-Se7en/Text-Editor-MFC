#include<string>
#include<iostream>
#include<ctype.h>
#ifndef MY_HEADER8
#define MY_HEADER8
using namespace std;
int key_gen() {
    int key;
    srand(time(0));//seeding the random nuber generator using the unix epoch
    key = rand() % 25 + 1;//between 1 to 25
    return key;
}
CString encrypt(CString not_encrypted, int key) {
    CString encrypted = L"";
    for (int i = 0; i < not_encrypted.GetLength(); i++) {
        char c = not_encrypted[i];
        if (iswalpha(c)) {
            if (iswupper(c))
                c = ((c + key - 65) ) + 65;
            else
                c = ((c + key - 97) ) + 97;
        }
        else if (iswdigit(c)) {
            c += key ;
        }
        else {
            c += key;
        }
        encrypted += c;
    }
    return encrypted;
}

CString decrypt(CString not_decrypted, int key) {
    CString decrypted = L"";
    for (int i = 0; i < not_decrypted.GetLength(); i++) {
        char c = not_decrypted[i];
        if (iswalpha(c)) {
            if (iswupper(c))
                c = ((c - key - 65) ) + 65;
            else
                c = ((c - key - 97) ) + 97;
        }
        else if (iswdigit(c)) {
            c -= key ;
        }
        else {
            c -= key;
        }
        decrypted += c;
    }
    return decrypted;
}
wstring encrypt(wstring not_encrypted, int key) {
    wstring encrypted = L"";
    for (int i = 0; i < not_encrypted.length(); i++) {
        wchar_t c = not_encrypted[i];
        if (iswalpha(c)) {
            if (iswupper(c))
                c = ((c + key - 65)) + 65;
            else
                c = ((c + key - 97)) + 97;
        }
        else if (iswdigit(c)) {
            c += key;
        }
        else {
            c += key;
        }
        encrypted += c;
    }
    return encrypted;
}

wstring decrypt(wstring not_decrypted, int key) {
    wstring decrypted = L"";
    for (int i = 0; i < not_decrypted.length(); i++) {
        wchar_t c = not_decrypted[i];
        if (iswalpha(c)) {
            if (iswupper(c))
                c = ((c - key - 65)) + 65;
            else
                c = ((c - key - 97)) + 97;
        }
        else if (iswdigit(c)) {
            c -= key;
        }
        else {
            c -= key;
        }
        decrypted += c;
    }
    return decrypted;
}
#endif
