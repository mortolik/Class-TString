#include "TString.h"
#include <iostream>

int main()
{
    TString s1, s2,s3;
    s1 = "Hello";
    s2 = "Hellm";
    s3 = "Hel";
    bool sravn{ s1 >= s2 };
    cout << sravn;
    bool sravn1{ s1 >= s3 };
    cout << sravn1;
}