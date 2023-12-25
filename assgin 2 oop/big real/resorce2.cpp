#include "bigreal.h"
bigreal ::bigreal() {
    integer='0';
    fraction='0';
    Sign='+';
    receved_number = "0.0";
}
bool bigreal::ValiDation(string realNumber) {
    regex validInput("[-+]?[0-9]*[.]?[0-9]+");
    return regex_match(realNumber, validInput);
}
void bigreal :: SetNumber(string realNumber)
{
    if(realNumber[0] == '+')
    {
        realNumber.erase(realNumber.begin());
        Sign = '+';
    }
    else if (realNumber[0] == '-')
    {
        realNumber.erase(realNumber.begin());
        Sign = '-';
    }
    else
    {
        Sign = '+';
    }
    num_with_frac=realNumber;

}
bigreal :: bigreal(string realNumber) {
    if (ValiDation(realNumber)) {
        SetNumber(realNumber);
        receved_number = realNumber;
        realNumber = num_with_frac;
        int index = realNumber.find(".");
        if(!(index == string::npos)){
            integer = realNumber.substr(0, realNumber.find('.'));
            fraction = realNumber.substr(integer.size()+1 , realNumber.size()-1);
            if (realNumber[0] == '.' )
                integer = "0";
        }
        else if ( realNumber[0] == '.' )
            fraction = realNumber.substr(1,realNumber.size()-1);
        else
            integer = realNumber;
    }
}

bigreal :: bigreal (string realNumer1 , string realNumber2){
    if (ValiDation(realNumer1) && ValiDation (realNumber2)){
        bigreal r1(realNumer1),r2(realNumber2);
        cout<<r1.integer<<r2.integer;
    }
    else
        cout<<"invalid number";
}

bool bigreal :: operator < (const bigreal& anotherDec)
{

        bigreal num1 = receved_number, num2 = anotherDec.receved_number;

        if (Sign == '+' && anotherDec.Sign == '-') {
            return false; // If this is positive and anotherDec is negative, this is greater.
        } else if (Sign == '-' && anotherDec.Sign == '+') {
            return true; // If this is negative and anotherDec is positive, this is smaller.
        } else {
            // Both have the same sign, compare integer and fraction parts.
            if (integer != anotherDec.integer) {
                return (Sign == '+') ? (integer < anotherDec.integer) : (integer > anotherDec.integer);
            } else {
                return (Sign == '+') ? (fraction < anotherDec.fraction) : (fraction > anotherDec.fraction);
            }

        }

}
bool bigreal :: operator > (const bigreal& anotherDec)
{
    bigreal num1 = receved_number , num2 = anotherDec.receved_number;

    if (Sign == '+' && anotherDec.Sign == '-')
    {
        return true; // If this is positive and anotherDec is negative, this is greater.
    }
    else if (Sign == '-' && anotherDec.Sign == '+') {
        return false; // If this is negative and anotherDec is positive, this is smaller.
    }
    else
    {
        // Both have the same sign, compare integer and fraction parts.
        if (integer != anotherDec.integer) {
            return (Sign == '+') ? (integer > anotherDec.integer) : (integer < anotherDec.integer);
        }
        else {
            return (Sign == '+') ? (fraction > anotherDec.fraction) : (fraction < anotherDec.fraction);
        }

    }


}
bool bigreal :: operator == (const bigreal anotherDec)
{
    if(Sign == anotherDec.Sign && integer == anotherDec.integer && fraction == anotherDec.fraction)
        return true;
    else
        return false;
}
bigreal bigreal :: operator + (bigreal onthernumber){
    if (ValiDation (onthernumber.receved_number) && ValiDation (receved_number)) {
        string rusult1, rusult2;
        int comand;
        char carry = '0', temp;
        bigreal num1 = receved_number, num2 = onthernumber.receved_number;
        string intr1 = num1.integer, intr2 = num2.integer;
        string frac1 = num1.fraction, frac2 = num2.fraction;
        if (num1.Sign == num2.Sign) {
            if (frac1.size() < frac2.size())
                rusult1 = frac2.substr(frac1.size(), frac2.size() - 1);
            else
                rusult1 = frac1.substr(frac2.size(), frac1.size() - 1);
            if (frac1.size() < frac2.size())
                comand = frac1.size();
            else
                comand = frac2.size();
            for (int i = comand - 1; i >= 0; i--) {
                int number1;
                temp = carry - '40' + frac1[i] + frac2[i] - '80';
                if (temp > '9') {
                    carry = '1';
                    temp = temp - 10;
                } else
                    carry = '0';
                rusult1 = temp + rusult1;
            }
            //=================================================
            string zeros;
            if (intr1.size() < intr2.size()) {
                for (int i = 0; i < intr2.size() - intr1.size(); ++i) {
                    zeros = zeros + '0';
                }
                intr1 = zeros + intr1;
            } else {
                for (int i = 0; i < intr1.size() - intr2.size(); ++i) {
                    zeros = zeros + '0';
                }
                intr2 = zeros + intr2;
            }
            for (int i = intr1.size() - 1; i >= 0; i--) {
                int number1;
                temp = carry - '40' + intr1[i] + intr2[i] - '80';
                if (temp > '9') {
                    carry = '1';
                    temp = temp - 10;
                } else
                    carry = '0';
                rusult2 = temp + rusult2;
            }
            if (carry == '1')
                rusult2 = '1' + rusult2;
            //========================================
            cout << num1.Sign << rusult2 << '.' << rusult1 << endl;

        } else if (num1.Sign != num2.Sign) {
            if (num2.Sign == '-')
                num2.Sign = '+';
            else
                num2.Sign = '-';
            bigreal rusult = num1 - num2;
        }
    }
    else {
        cout << "one of this number isn't validation or both if you want pause\n";
        system("pause");
    }
}

bigreal bigreal::operator - (bigreal SecondNumber) {
    if (ValiDation (SecondNumber.receved_number) && ValiDation (receved_number)) {
        bigreal result;
        int carry = 0, sub;
        string subinteger = "", subfraction = "";
        while (integer.size() > SecondNumber.integer.size()) {
            SecondNumber.integer = "0" + SecondNumber.integer;
        }
        while (integer.size() < SecondNumber.integer.size()) {
            integer = "0" + integer;
        }
        while (fraction.size() > SecondNumber.fraction.size()) {
            SecondNumber.fraction.push_back('0');
        }
        while (fraction.size() < SecondNumber.fraction.size()) {
            fraction.push_back('0');
        }
        int bsize = integer.size();
        int asize = fraction.size();
        //case 1: + +
        if (Sign == '+' && SecondNumber.Sign == '+') {
            if (*this > (SecondNumber)) {
                for (int i = bsize - 1; i >= 0; i--) {
                    sub = ((integer[i] - '0') - (SecondNumber.integer[i] - '0') - carry);
                    if (sub < 0) {
                        sub += 10;
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    subinteger.push_back(sub + '0');
                }
                reverse(subinteger.begin(), subinteger.end());
                carry = 0;
                for (int i = asize -1 ; i > -1; i--) {
                    sub = ((fraction[i] - '0') - (SecondNumber.fraction[i] - '0') - carry);
                    if (sub < 0) {
                        sub += 10;
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    subfraction.push_back(sub + '0');
                }
                if (carry == 1 && subinteger[subinteger.size() - 1] == '0') {
                    for (int i = 0; i < subinteger.size(); i++) {
                        if (subinteger[i] == '0') {
                            subinteger[i] = '9';
                        } else {
                            subinteger[i] = (subinteger[i] - '0') - 1 + '0';
                        }
                    }
                    carry = 0;
                } else if (carry) {
                    subinteger[subinteger.size() - 1] = ((subinteger[subinteger.size() - 1] - '0') - carry + '0');
                }
                reverse(subfraction.begin(), subfraction.end());
            } else if (*this < (SecondNumber)) {
                for (int i = bsize - 1; i >= 0; i--) {
                    sub = ((SecondNumber.integer[i] - '0') - (integer[i] - '0') - carry);
                    if (sub < 0) {
                        sub += 10;
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    subinteger.push_back(sub + '0');
                }
                reverse(subinteger.begin(), subinteger.end());
                for (int i = asize - 1; i > 0; i--) {
                    sub = ((SecondNumber.fraction[i] - '0') - (fraction[i] - '0') - carry);
                    if (sub < 0) {
                        sub += 10;
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    subfraction.push_back(sub + '0');
                }
                if (carry == 1 && subinteger[subinteger.size() - 1] == '0') {
                    for (int i = 0; i < subinteger.size(); i++) {
                        if (subinteger[i] == '0') {
                            subinteger[i] = '9';
                        } else {
                            subinteger[i] = (subinteger[i] - '0') - 1 + '0';
                        }
                    }
                    carry = 0;
                } else if (carry) {
                    subinteger[subinteger.size() - 1] = ((subinteger[subinteger.size() - 1] - '0') - carry + '0');
                }
                reverse(subfraction.begin(), subfraction.end());

                result.Sign = '-';
            } else if (*this == (SecondNumber)) {
                subinteger = "0";
                subfraction = ".0";
            }

        }
        //case 2: + -
        if (Sign == '+' && SecondNumber.Sign == '-') {
            for (int i = bsize - 1; i >= 0; i--) {
                sub = ((integer[i] - '0') + (SecondNumber.integer[i] - '0') + carry);
                subinteger.push_back(sub % 10 + '0');
                carry = sub / 10;
            }
            if (carry) {
                subinteger.push_back(carry + '0');
            }
            reverse(subinteger.begin(), subinteger.end());
            carry = 0;
            for (int i = asize - 1; i > -1; i--) {
                sub = ((fraction[i] - '0') + (SecondNumber.fraction[i] - '0') + carry);
                subfraction.push_back(sub % 10 + '0');
                carry = sub / 10;
            }
            if (carry == 1 && subinteger[subinteger.size() - 1] == '9') {
                if (subinteger[0] == '9') {
                    for (int i = 0; i < subinteger.size(); i++) {
                        if (subinteger[i] == '9') {
                            subinteger[i] = '0';
                        } else {
                            subinteger[i] = subinteger[i] + 1;
                        }
                    }
                    subinteger = "1" + subinteger;
                } else {
                    subinteger[0] = subinteger[0] + 1;
                    for (int i = 1; i < subinteger.size(); i++) {
                        if (subinteger[i] == '9') {
                            subinteger[i] = '0';
                        } else {
                            subinteger[i] = subinteger[i] + 1;
                        }
                    }

                }
                carry = 0;
            } else if (carry) {
                subinteger[subinteger.size() - 1] = ((subinteger[subinteger.size() - 1] - '0') + carry + '0');
            }
            reverse(subfraction.begin(), subfraction.end());

        }

        //case 3: - +
        if (Sign == '-' && SecondNumber.Sign == '+') {
            for (int i = bsize - 1; i >= 0; i--) {
                sub = ((integer[i] - '0') + (SecondNumber.integer[i] - '0') + carry);
                subinteger.push_back(sub % 10 + '0');
                carry = sub / 10;
            }
            if (carry) {
                subinteger.push_back(carry + '0');
            }
            reverse(subinteger.begin(), subinteger.end());
            carry = 0;
            for (int i = asize - 1; i > -1; i--) {
                sub = ((fraction[i] - '0') + (SecondNumber.fraction[i] - '0') + carry);
                subfraction.push_back(sub % 10 + '0');
                carry = sub / 10;
            }
            if (carry == 1 && subinteger[subinteger.size() - 1] == '9') {
                if (subinteger[0] == '9') {
                    for (int i = 0; i < subinteger.size(); i++) {
                        if (subinteger[i] == '9') {
                            subinteger[i] = '0';
                        } else {
                            subinteger[i] = subinteger[i] - '0' + 1 + '0';
                        }
                    }
                    subinteger = "1" + subinteger;
                } else {
                    subinteger[0] = subinteger[0] - '0' + 1 + '0';
                    for (int i = 1; i < subinteger.size(); i++) {
                        if (subinteger[i] == '9') {
                            subinteger[i] = '0';
                        } else {
                            subinteger[i] = subinteger[i] - '0' + 1 + '0';
                        }
                    }

                }
                carry = 0;
            } else if (carry) {
                subinteger[subinteger.size() - 1] = ((subinteger[subinteger.size() - 1] - '0') + carry + '0');
            }
            reverse(subfraction.begin(), subfraction.end());
            result.Sign = '-';
        }

        //case 4: - -
        if (Sign == '-' && SecondNumber.Sign == '-') {
            if (operator<(SecondNumber) == 1) {
                for (int i = bsize - 1; i >= 0; i--) {
                    sub = ((integer[i] - '0') - (SecondNumber.integer[i] - '0') - carry);
                    if (sub < 0) {
                        sub += 10;
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    subinteger.push_back(sub + '0');
                }
                reverse(subinteger.begin(), subinteger.end());
                carry = 0;
                for (int i = asize - 1; i > -1; i--) {
                    sub = ((fraction[i] - '0') - (SecondNumber.fraction[i] - '0') - carry);
                    if (sub < 0) {
                        sub += 10;
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    subfraction.push_back(sub + '0');
                }
                if (carry == 1 && subinteger[subinteger.size() - 1] == '0') {
                    for (int i = 0; i < subinteger.size(); i++) {
                        if (subinteger[i] == '0') {
                            subinteger[i] = '9';
                        } else {
                            subinteger[i] = (subinteger[i] - '0') - 1 + '0';
                        }
                    }
                    carry = 0;
                } else if (carry) {
                    subinteger[subinteger.size() - 1] = ((subinteger[subinteger.size() - 1] - '0') - carry + '0');
                }
                reverse(subfraction.begin(), subfraction.end());
                result.Sign = '-';
            } else if (operator>(SecondNumber) == 1) {
                for (int i = bsize - 1; i >= 0; i--) {
                    sub = ((SecondNumber.integer[i] - '0') - (integer[i] - '0') - carry);
                    if (sub < 0) {
                        sub += 10;
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    subinteger.push_back(sub + '0');
                }
                reverse(subinteger.begin(), subinteger.end());
                carry = 0;
                for (int i = asize - 1; i >= 0; i--) {
                    sub = ((SecondNumber.fraction[i] - '0') - (fraction[i] - '0') - carry);
                    if (sub < 0) {
                        sub += 10;
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    subfraction.push_back(sub + '0');
                }
                if (carry == 1 && subinteger[subinteger.size() - 1] == '0') {
                    for (int i = 0; i < subinteger.size(); i++) {
                        if (subinteger[i] == '0') {
                            subinteger[i] = '9';
                        } else {
                            subinteger[i] = (subinteger[i] - '0') - 1 + '0';
                        }
                    }
                    carry = 0;
                } else if (carry) {
                    subinteger[subinteger.size() - 1] = ((subinteger[subinteger.size() - 1] - '0') - carry + '0');
                }
                reverse(subfraction.begin(), subfraction.end());
            } else if (operator==(SecondNumber) == 1) {
                subinteger = "0";
                subfraction = ".0";
            }


        }

        int c = 0;
        for (int i = 0; i < subinteger.size(); i++) {
            if (subinteger[i] == '0') {
                c++;
            } else {
                break;
            }
        }
        if (c == subinteger.size()) {
            subinteger = "0";
        } else {
            while (subinteger[0] == '0') {
                subinteger = subinteger.substr(1, subinteger.size() - 1);
            }
        }
        if (subinteger == "0" && subfraction == "0") {
            result.integer = subinteger;
            result.fraction = '.' + subfraction;
            return result;
        } else {
            while (subfraction[subfraction.size() - 1] == '0') {
                subfraction.pop_back();
            }
            result.integer = subinteger;
            result.fraction = '.' + subfraction;
            cout<<result.Sign<<result.integer<<result.fraction<<endl;
            return result;
        }
    }
    else{
        cout << "one of this number isn't validation or both if you want pause\n";
        system("pause");
    }

}
bigreal bigreal::operator = (bigreal& SecondNumber){
    Sign = SecondNumber.Sign;
    integer = SecondNumber.integer;
    fraction = SecondNumber.fraction;
    return SecondNumber;
}
void bigreal ::print() {
    cout <<endl<< Sign << integer << '.' << fraction<<"\n";
}

