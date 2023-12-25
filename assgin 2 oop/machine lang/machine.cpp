#include "machine.h"
//=================================================
void set_file(string &fnal) {
    string filename;
    string input;
    // Get the file name from the user
    cout << "Enter the file name: ";
    cin >> filename;

    // Check if the file exists and can be opened
    ifstream fileStream(filename);
    if (fileStream.is_open())
    {
        cout << "File exists and can be opened." << endl;

        // Read the content of the file
        string line, content = "";

        cout << "File content:" << endl;
        while (getline(fileStream, line))
        {
            content += line;
        }
        for ( int i = 0; i < content.size(); i++)
        {
            if (int(content[i]) == 32 )
            {
                content.erase(i, 1);
            }
        }
        for ( int i = 0; i < content.size(); i++)
        {
            if(int(content[i]) == 48 && int(content[i + 1]) == 120)
            {
                content.erase(i, 2);
            }
        }
        fnal = content;
        // Close the file stream
        fileStream.close();
    }
    else
    {
        cout << "File does not exist or cannot be opened." << endl;

    }
}
string convertToHex(const string& num) {
    std::stringstream ss;
    ss << hex << stoi(num);
    return ss.str();
}
int hex_to_int2(string hex_string) {
    int value = 0;
    int base = 1;
    for (int i = hex_string.length() - 1; i >= 0; i--) {
        char hex_digit = hex_string[i];
        int digit_value = 0;
        if (hex_digit >= '0' && hex_digit <= '9') {
            //Convert to int
            digit_value = hex_digit - '0';
        } else if (hex_digit >= 'A' && hex_digit <= 'F') {
            //Convert to int
            digit_value = hex_digit - 'A' + 10;
        } else {
            return -1; // Not a hexa digit
        }
        value += digit_value * base;
        base *= 16;
    }
    return value;
}
//=================================================
Machine::Machine(string input){
    //make value and address = 0
    for (int i = 0; i < 16; i++) {
        R[i].address = i;
        R[i].value = "00";
    }
    for (int i = 0; i < 256; i++) {
        M[i].address = i;
        M[i].value = "00";
    }
    int mano=0;
    for (size_t i = 0; i < input.length(); i += 2) {
        //input memory
        string substring = input.substr(i, 2);
        M[mano].value=substring;
        mano++;
    }
}
//=================================================
void one(string input_num , Machine &p){
    //1RXY go to addres XY and put this value in R 14A3
    string res = input_num.substr(1, 1);
    string xy = input_num.substr(2, 4);
    int res_add =hex_to_int2 (res);
    int xy_add =hex_to_int2 (xy);
    p.R[res_add].value = p.M[xy_add].value;
}
//=================================================
void two(string input_num , Machine &p){
    //2RXY take value XY and put it in R  20A3
    string res = input_num.substr(1, 1);
    string xy = input_num.substr(2, 4);
    int res_add = hex_to_int2 (res);
    p.R[res_add].value = xy;
}
//=================================================
void three(string input_num , Machine &p){
    //3RXY take value in R and put in addres XY  35B1
    string res = input_num.substr(1, 1);
    string xy = input_num.substr(2, 4);
    int res_add = hex_to_int2 (res);
    int xy_add = hex_to_int2 (xy) ;
    p.M[xy_add].value = p.R[res_add].value;
}
//=================================================
void four(string input_num , Machine &p){
    //40RS take vakue in R and cpied it in rigester S 4046
    string res1 = input_num.substr(2, 1);
    string res2 = input_num.substr(3, 4);
    int res_add1 = hex_to_int2 (res1);
    int res_add2 = hex_to_int2 (res2);
    p.R[res_add2].value = p.R[res_add1].value;
}
//=================================================
void five(string input_num , Machine &p){
    //5RST take value in rigester S,T and plus it by two’s complement and put rusult in R
    string res1 = input_num.substr(1, 1);
    string res2 = input_num.substr(2, 1);
    string res3 = input_num.substr(3, 4);
    int res_add1 = hex_to_int2 (res1);
    int res_add2 = hex_to_int2 (res2);
    int res_add3 = hex_to_int2 (res2);
    int num2 = hex_to_int2(p.R[res_add2].value);
    int num3 = hex_to_int2(p.R[res_add3].value);
    string num1 = to_string(num2+num3);
    if (num1.size() == 1)
        num1="0"+num1;
    else if (num1.size() == 3){
        string hh = num1;
        num1 = convertToHex(hh);
    }
    p.R[res_add1].value = num1;
}
//=================================================

//=================================================
void Machine::print() {
    for (int i = 0; i <16 ; ++i) {
        cout<<"regester"<<i<<" = "<<R[i].value<<endl;
    }
    for (int i = 0; i <256 ; ++i) {
        cout<<"memory"<<i<<" = "<<M[i].value<<endl;
    }
}
//=================================================