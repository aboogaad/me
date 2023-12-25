#include "machine.cpp"
int main() {
      string input;
      set_file(input);
      cout<<input<<endl;
      Machine GG=input;
      for (int i = 0; i <256 ; i += 4) {
            string input_num = input.substr(i, 4);
            if (input_num[0] == '1'){
                //1RXY go to addres XY and put this value in R 14A3
                one(input_num,GG);
            }
            else if (input_num[0] == '2'){
                //2RXY take value XY and put it in R  20A3
                two(input_num,GG);
            }
            else if (input_num[0] == '3'){
                //3RXY take value in R and put in addres XY  35B1
                three(input_num,GG);
            }
            else if (input_num[0] == '4'){
                //40RS take vakue in R and cpied it in rigester S
                four(input_num,GG);
            }
            else if (input_num[0] == '5'){
                //5RST take value in rigester S,T and plus it by two’s complement and put rusult in R
                five(input_num,GG);
            }
            else if (input_num[0] == 'C'){
                break;
            }
      }
    GG.print();
}
