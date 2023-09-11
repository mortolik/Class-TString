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
//istream& operator >> (istream& is,  const TString& str)
//{
//	is >> str.len;
//	return is;
//}

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

