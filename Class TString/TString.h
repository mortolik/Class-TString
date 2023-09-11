#pragma once
#include <iostream>
using namespace std;
class TString
{
	char* str;
	int len;
	static int count;
	static const int LIM = 80;
public:
	TString();
	TString(const char* s);
	TString(const TString& s);
	~TString();
	TString& operator=(const TString& s);
	TString& operator=(const char * s);
	char & operator [](const int i);
	const char& operator [] (int i) const { return str[i]; }
	int symb(const char s);
	bool operator== (const TString& s);
	bool operator!= (const TString& s);
	bool operator < (const TString& s);
	bool operator > (const TString& s);
	bool operator >= (const TString& s);
	bool operator <= (const TString& s);
	friend ostream& operator << (ostream& os, const TString& s);
	friend istream& operator >> (istream& is, TString& str);
};

