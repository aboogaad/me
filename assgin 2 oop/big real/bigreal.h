#ifndef BIG_REAL_BIGREAL_H
#define BIG_REAL_BIGREAL_H
#include <iostream>
#include <deque>
#include <regex>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class bigreal{
    char Sign = '+';
    string num_with_frac , receved_number , integer = "0" , fraction = "0";
    bool ValiDation(string realNumber);//check this validation
    void SetNumber (string realNumber);//know sign and save it alone and earse it

public:
    bigreal ();
    bigreal (string realNumber);//divided to two parts ,part1 = integer ,part2 = fraction
    bigreal (string realNumer1 , string realNumber2);//we didnt use it

    bool operator < (const bigreal& anotherDec);
    bool operator > (const bigreal& anotherDec);
    bool operator == (const bigreal anotherDec);

    bigreal operator + (bigreal onthernumber);
    bigreal operator - (bigreal onthernumber);
    bigreal operator = (bigreal& onthernumber);


    void print();// we didnt use it
};

#endif //BIG_REAL_BIGREAL_H
