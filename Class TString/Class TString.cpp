#include "TString.h"
#include <iostream>

int main()
{
    TString str;
    TString s = "hi";
    str = "Hello";
    cout << str << endl;
    str = s;
    cout << str << endl;
    int countSym=str.symb('l');
    cout << countSym;
}