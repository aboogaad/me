#ifndef FINAL_VIRISION_MACHINE_H
#define FINAL_VIRISION_MACHINE_H
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
class Rigester{
public:
    int address;
    string value;
};
class Memory{
public:
    int address;
    string value;
};
class Machine{
    vector<Rigester> R{16};
    vector<Memory> M{256};
public:
    Machine(string input);
    void print();
    friend void one(string input_num , Machine &p);
    friend void two(string input_num , Machine &p);
    friend void three(string input_num , Machine &p);
    friend void four(string input_num , Machine &p);
    friend void five(string input_num , Machine &p);
};
#endif
