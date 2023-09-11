#define _CRT_SECURE_NO_WARNINGS
#include "TString.h"
#include <iostream>

using namespace std;
int TString::count = 0;
TString::TString() { str = new char[1]; str[0] = '\0'; count++; }
TString::TString(const char* s) 
{	len = strlen(s); 
	str = new char[len + 1];
	strcpy(str, s);
	count++;
}
TString::TString(const TString &s) 
{	len = s.len; 
	str = new char[len + 1];
	strcpy(str, s.str);
	count++;
}
TString::~TString() { delete[]str; count--;}
TString& TString::operator=(const TString& s)
{
	if (this != &s)
	{
		if (len = s.len)
		{
			delete[] str;
			len = s.len;
			str = new char[len + 1];
		}
		strcpy(str, s.str);
	}
	return *this;
}
TString& TString::operator=(const char* s)
{
		if (len = strlen(s))
		{
			delete[] str;
			len = strlen(s);
			str = new char[len + 1];
		}
		strcpy(str, s);
	return *this;
}
char& TString:: operator [](const int i)
{
	return str[i];
}
ostream& operator << (ostream& os, const TString& s)
{
	os << s.str;
	return os;
}
istream& operator >> (istream& is, TString& s)
{
	char* limS = new char[TString::LIM + 1];
	is.get(limS, TString::LIM);
	if (is) { s = limS; }
	while (is.get() != '\n' && is);
	delete[] limS;
	return is;
}
int TString::symb(const char s)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == s) 
			count++;
	}
	return count;
}


bool TString :: operator==(const TString& s)
{
	if (len != s.len) return false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != s.str[i])return false;
	}
	return true;
}
bool TString :: operator != (const TString& s)
{
	return!(*this == s);
}
bool TString :: operator<(const TString& s)
{
	int minLen;
	if (len > s.len) minLen = s.len;
	else { minLen = len; }
	for (int i = 0; i < minLen; i++)
	{
		if (str[i] > s.str[i]) return false;
		else if (str[i] < s.str[i]) { return true; }
	}
	if (len < s.len) return true;
	else { return false; }
}
bool TString :: operator>(const TString& s)
{
	if (*this < s) return false;
	if (*this == s) return false;
	else return true;
}
bool TString :: operator<=(const TString& s)
{
	if (*this < s || *this == s) return true;
}
bool TString :: operator>=(const TString& s)
{
	if (*this > s || *this == s) return true;
}

