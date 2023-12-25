#include "resorce2.cpp"
int main() {
    string n1 = "2100000000000000000066.00000000003166", n2 = "23.62133216", n3 = "504000", n4 = "74.64";
    bigreal input (n1) , input2 (n2) ;

    bigreal e = input + input2;
//    bigreal m = input - input2;

    cout<<endl<<(input<input2);
    cout<<endl<<(input>input2);
    cout<<endl<<(input==input2);

    input = input2;
    input.print();
}