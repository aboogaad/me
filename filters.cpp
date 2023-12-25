// Assignment - 2023 – Programming OOP – FCAI
// Last Modification Date : 10/19/2023
// Author 1 : mohamed arafa sayed  
// Author 2 : yossef reda
// Author 3 : Abdelrahman Ahmed Farouk
// Purpose : 
#include<bits/stdc++.h>
#include<cstring>
#include<fstream>
#include<bmplib.h>
#include"bmplib.cpp"
using namespace std;
unsigned char imageRGB[SIZE][SIZE][RGB];
unsigned char imageRGB2[SIZE][SIZE][RGB];
void loadImage ();
void loadSecondImage ();
void blackAndWhite ();
void invert ();
void flip ();
void mergeImages ();
void mirror ();
void lighten ();
void darken ();
void enlarge ();
void skewVertically ();
void skewHorizontally ();
void shuffle ();
void shrinkImage ();
void shrinkImage3 ();
void blur ();
void crop ();
void rotate ();
void edge ();
void saveImage ();
int main(){
    char filter = '1';
    loadImage ();
    while (filter != '0'){
        cout << "\nPlease Choose the filter you wish to use or 0 to terminate :  \n";
        cout << "1- Black & White Filter \n2- Invert Filter \n3- Merge Filter \n4- Flip Image \n5- Rotate Image \n6- Darken and Lighten Image \n7- Detect Image Edges \n8- Enlarge Image \n9- Shrink Image \na- Mirror  Image \nb- Shuffle Image \nc- Blur Image \nd- Crop Image \ne- Skew Image Right \nf- Skew Image Up \ns- Save the image to a file \n" ;
        cin >> filter;
        filter = tolower(filter);
        switch (filter){
            case '1':
                blackAndWhite ();
                break;
            case '2':
                invert ();
                break;
            case '3':
                loadSecondImage ();
                mergeImages ();
                break;
            case '4':
                flip ();
                break;
            case '5':
                rotate ();
                break;
            case '6':
                int choice;
                cout << "1- Lighten\n2- Darken\n Please enter the filter you which to apply : ";
                cin >> choice;
                if (choice  == 1){
                    lighten ();
                }
                else {
                    darken ();
                }
                break;
            case '7':
                edge ();
                break;
            case '8':
                enlarge ();
                break;
            case '9':
                int reduce;
                cout<<"1- Reduce image's size to half\n2- Reduce image's size to third\n3- Reduce image's size to quarter\n";
                cin>>reduce;
                if (reduce == 1){
                    shrinkImage ();
                }
                else if (reduce == 2){
                    shrinkImage3 ();
                }
                else{
                    shrinkImage ();
                    shrinkImage ();
                }
                break;
            case 'a':
                mirror ();
                break;
            case 'b':
                shuffle ();
                break;
            case 'c':
                blur ();
                break;
            case 'd':
                crop ();
                break;
            case 'e':
                skewHorizontally ();
                break;
            case 'f':
                skewVertically ();
                break;
            case '0':
                break;
            case 's':
                saveImage ();
                break;
            default:
                cout << "\nPlease enter a valid option\n";
        }
    }
}
//---------------------------------------------------------------------
void blackAndWhite (){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            int avg = (imageRGB[i][j][0] + imageRGB[i][j][1] + imageRGB[i][j][2]) / 3;
            if(avg > 127){
                imageRGB[i][j][0] = 255;
                imageRGB[i][j][1] = 255;
                imageRGB[i][j][2] = 255;
            }
            else{
                imageRGB[i][j][0] = 0;
                imageRGB[i][j][1] = 0;
                imageRGB[i][j][2] = 0;
            }
        }
    }
}
//---------------------------------------------------------------------
void loadImage (){
    char input[100];
    cout << "Please Enter The File's Name : ";
    cin >> input;
    strcat (input, ".bmp");
    readRGBBMP (input, imageRGB);
}
//---------------------------------------------------------------------
void loadSecondImage (){
    char input[100];
    cout << "Please Enter The File's Name : ";
    cin >> input;
    strcat (input, ".bmp");
    readRGBBMP (input, imageRGB2);
}  
//---------------------------------------------------------------------
void invert (){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k < RGB; k++){
                imageRGB[i][j][k] = 255 - imageRGB[i][j][k];
            }
        }
    }
}
//---------------------------------------------------------------------
void mergeImages() {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k < RGB; k++){
                int temp;
                temp = imageRGB[i][j][k] / 2;
                imageRGB2[i][j][k] = imageRGB2[i][j][k] / 2;
                imageRGB[i][j][k] = imageRGB2[i][j][k] + temp;
            }
        }        
    }
}
//---------------------------------------------------------------------
void lighten() {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++){
                int ms;
                ms = SIZE - imageRGB[i][j][k];
                imageRGB[i][j][k] = imageRGB[i][j][k] + (ms / 2);
            }
            
        }
    }
}
//---------------------------------------------------------------------
void darken() {
    for (int i = 0; i < SIZE; i++)  {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++){
                imageRGB[i][j][k] = imageRGB[i][j][k] / 2;
            }
        }
    }
}
//---------------------------------------------------------------------
void flip (){
    int flip;
    cout << "1- Horizontal\n2- Vertical \nPlease enter the filter you which to apply : ";
    cin >> flip;
    switch (flip){
        case 1:
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE / 2; j++){
                    for (int k = 0; k < RGB; k++){
                        swap (imageRGB[i][j][k], imageRGB[i][SIZE - 1 - j][k]);
                }  
                    }
            }
            break;
        case 2:
            for (int i = 0; i < SIZE / 2; i++){
                for (int j = 0; j < SIZE; j++){
                    for (int k = 0; k < RGB; k++){
                        swap (imageRGB[i][j][k], imageRGB[SIZE - 1 - i][j][k]); 
                    }
                }
            }
        break;
    }  
}
//---------------------------------------------------------------------
void mirror (){
    int half;
    cout << "\n1- Upper\n2- Lower\n3- Right\n4- Left\n Please choose the quarter you want to mirror : ";
    cin >> half;
    switch (half){
        case 1:
            for (int i = 0; i < SIZE / 2; i++){
                for (int j = 0; j < SIZE; j++){
                    for (int k = 0; k < RGB; k++){
                        imageRGB[SIZE - 1 - i][j][k] = imageRGB[i][j][k];
                    } 
                }
            }
        break;
        case 2:
            for (int i = 0; i < SIZE / 2; i++){
                for (int j = 0; j < SIZE; j++){
                    for (int k = 0; k < RGB; k++){
                        imageRGB[i][j][k] = imageRGB[SIZE - 1 - i][j][k];
                    }  
                }
            }
        break;
        case 3:
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE / 2; j++){
                    for (int k = 0; k < RGB; k++){
                        imageRGB[i][j][k] = imageRGB[i][SIZE - 1 - j][k];
                    }  
                }
            }
        break;
        case 4:
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE / 2; j++){
                    for (int k = 0; k < RGB; k++){
                        imageRGB[i][SIZE - 1 - j][k] = imageRGB[i][j][k];
                    } 
                }
            }
        break;
   }
}
//---------------------------------------------------------------------
void crop (){
    int x, y, l, w;
    cout << "Please enter x, y, l, w : ";
    cin >> x >> y >> l >> w;
    int Hlimit = x + l;
    int Vlimit = y + w;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k < RGB; k++){
                if ((i < x) || (i > Hlimit) || (j < y) || (j > Vlimit)){
                    imageRGB[i][j][k] = 255;
                }
            }    
        }
    }
}
//---------------------------------------------------------------------
void enlarge (){
    int quarter, flag, r = 0, c = 0;
    cout << "Please choose which quarter to enlarge 1, 2, 3 or 4 : ";
    cin >> quarter;
    if(quarter < 3){
      flag = 0;
    }
    else{
      flag = 1;
    }
    for (int i = flag * (SIZE / 2); i < ((flag + 1) * (SIZE / 2)); i++){
        for (int j = ((quarter + 1) % 2) * (SIZE / 2); j < (128 + (((quarter + 1) % 2) * (SIZE / 2))); j++){
            for (int k = 0; k < RGB; k++){
                imageRGB2[c][r][k] = imageRGB[i][j][k];
                imageRGB2[c + 1][r][k] = imageRGB[i][j][k];
                imageRGB2[c][r + 1][k] = imageRGB[i][j][k];
                imageRGB2[c + 1][r + 1][k] = imageRGB[i][j][k];
            }
            r += 2;
        }
        r = 0;
        c += 2;
    }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k < RGB; k++){
                imageRGB[i][j][k] = imageRGB2[i][j][k];
            }
        }
    }
}
//---------------------------------------------------------------------
void blur (){
    for (int i = 1; i < SIZE; i++){
        for (int j = 1; j < SIZE; j++){
            for (int k = 0; k < RGB; k++){
                int avg = 0;
                avg = imageRGB[i][j][k] + imageRGB[i][j - 1][k] + imageRGB[i - 1][j][k] + imageRGB[i - 1][j - 1][k];
                imageRGB[i][j][k] = avg / 4;
            }
        }
    }
}
//---------------------------------------------------------------------
void rotate () {
    int rotationAngle;
    cout << "\nPlease Enter The Desired Rotation Angle (90, 180, 270, 360) : ";
    cin >> rotationAngle;
    while (rotationAngle){
        for (int i = 0; i < SIZE; i++) {
            for (int j = i; j < SIZE; j++) {
                for(int k = 0; k < RGB; k++){
                    swap (imageRGB[i][j][k], imageRGB[j][i][k]);
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            int n = 0;
            int m = SIZE - 1;
            while (n<m){
                for (int k = 0; k < RGB; k++){
                    swap (imageRGB[i][n][k], imageRGB[i][m][k]);
                }
                n++;
                m--;
            }
        }
        rotationAngle -= 90;
    }
}
//---------------------------------------------------------------------
void skewVertically () {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <RGB ; k++) {
                imageRGB2[i][j][k] = 255;
            }
        }
    }
    cout << "put the degree you want to skew Up : ";
    double degree,rad,angle,begin,move;
    cin >> degree;
    rad = degree * (M_PI / 180.0);
    angle = tan(rad);
    int x = 256 / (1 + (1 / angle));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <RGB ; k++) {
                imageRGB2[i][(j*x)/SIZE][k] = imageRGB[i][j][k];
            }
        }
    }
    begin= 256.0 - x;
    move = begin / 256.0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k <RGB ; k++) {
                imageRGB[i][j+int(begin)][k]=imageRGB2[i][j][k];
            }
        }
        begin-=move;
    }
}
//---------------------------------------------------------------------
void skewHorizontally () {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <RGB ; k++) {
                imageRGB2[i][j][k] = 255;
            }
        }
    }
    cout << "put the degree you want to skew Up : ";
    double degree, rad, angle, begin, move;
    cin >> degree;
    rad = degree * (M_PI / 180.0);
    angle = tan(rad);
    int x = 256 / (1 + (1 / angle));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <RGB ; k++) {
                imageRGB2[(i * x) / SIZE][j][k] = imageRGB[i][j][k];
                imageRGB[i][j][k] = 255;
            }
        }
    }
    begin = 256.0 - x;
    move = begin / 256.0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = begin; j < begin + x; j++) {
            for (int k = 0; k <RGB ; k++) {
                imageRGB[j][i][k] = imageRGB2[j - int(begin)][i][k];
            }
        }
        begin -= move;
    }
}
//---------------------------------------------------------------------
void shuffle (){
    cout << "\nPlease enter the order you want : ";
    string order;
    cin >> order;
    unsigned char* ptr;
    for (int t = 0; t < order.size(); t++){
        switch (t){
            case 0:
                ptr = &imageRGB2[0][0][0];
                break;
            case 1:
                ptr = &imageRGB2[0][SIZE / 2][0];
                break;
            case 2:
                ptr = &imageRGB2[SIZE / 2][0][0];
                break;
            case 3:
                ptr = &imageRGB2[SIZE / 2][SIZE / 2][0];
                break;
            default:
                break;
        }
        switch (order[t]){
            case '1':
                for (int i = 0; i < SIZE / 2; i++){
                    for (int j = 0; j < SIZE / 2; j++){
                        for (int k = 0; k <RGB ; k++) {
                            *ptr = imageRGB[i][j][k];
                            ptr++;
                        }
                    }
                    ptr += 3 *(SIZE / 2);
                }
                break;
            case '2':
                for (int i = 0; i < SIZE / 2; i++){
                    for (int j = SIZE / 2; j < SIZE; j++){
                        for (int k = 0; k <RGB ; k++) {
                            *ptr = imageRGB[i][j][k];
                            ptr++;
                        }
                        //ptr++;
                    }
                    ptr += 3 *(SIZE / 2);
                }
                break;
            case '3':
                for (int i = SIZE / 2; i < SIZE; i++){
                    for (int j = 0; j < SIZE / 2; j++){
                        for (int k = 0; k < RGB ; k++) {
                            *ptr = imageRGB[i][j][k];
                            ptr++;
                        }
                       //ptr++;
                    }
                    ptr += 3 *(SIZE / 2);
                }
                break;
            case '4':
                for (int i = SIZE / 2; i < SIZE; i++){
                    for (int j = SIZE / 2; j < SIZE; j++){
                        for (int k = 0; k < RGB ; k++) {
                            *ptr = imageRGB[i][j][k];
                            ptr++;
                        }
                        //ptr++;
                    }
                    ptr += 3 *(SIZE / 2);
                }
                break;
            default:
                break;
        }
    }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k <RGB ; k++) {
                imageRGB[i][j][k] = imageRGB2[i][j][k];
            }
        }
    }
}
//---------------------------------------------------------------------
void shrinkImage (){
    int h = 0, y = 0;
    for (int i = 0; i < SIZE; i++){
        h = 0;
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <RGB ; k++) {
                imageRGB[y][h][k] = (imageRGB[i][j][k] + imageRGB[i +1 ][j][k] + imageRGB[i][j + 1][k] + imageRGB[i + 1][j + 1][k]) / 4;//i take avrage every 4 bixels and but them in one
                imageRGB[i][j][k] = 255;
                imageRGB[i + 1][j][k] = 255;
                imageRGB[i][j + 1][k] = 255;
                imageRGB[i + 1][j + 1][k] = 255;
            }
            j++;
            h++;
        }
        y++;
        i++;
    }
}
//---------------------------------------------------------------------
void shrinkImage3 (){
    int h = 0, y = 0;
    for (int i = 0; i < SIZE; i++){
        h = 0;
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k <RGB ; k++) {
                imageRGB[y][h][k] = (imageRGB[i][j][k] + imageRGB[i + 1][j][k] + imageRGB[i][j + 1][k] + imageRGB[i + 1][j + 1][k] + imageRGB[i][j + 2][k] + imageRGB[i + 2][j][k] + imageRGB[i + 2][j + 1][k] + imageRGB[i + 1][j + 2][k] + imageRGB[i + 2][j + 2][k]) / 9;
                imageRGB[i][j][k] = 255;
                imageRGB[i + 1][j][k] = 255;
                imageRGB[i][j + 1][k] = 255;
                imageRGB[i + 1][j + 1][k] = 255;
                imageRGB[i][j + 2][k] = 255;
                imageRGB[i + 2][j][k] = 255;
                imageRGB[i + 2][j + 1][k] = 255;
                imageRGB[i + 1][j + 2][k] = 255;
                imageRGB[i + 2][j + 2][k] = 255;
            }
            j += 2;
            h++;
        }
        y++;
        i++;
        i++;
    }
}
//---------------------------------------------------------------------
void edge (){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            int avg = (imageRGB[i][j][0] + imageRGB[i][j][1] + imageRGB[i][j][2]) / 3;
            int ravg = (imageRGB[i][j + 1][0] + imageRGB[i][j + 1][1] + imageRGB[i][j + 1][2]) / 3;
            int bavg = (imageRGB[i + 1][j][0] + imageRGB[i + 1][j][1] + imageRGB[i + 1][j][2]) / 3;
            bool higher = false, lower = false;
            if (avg >= 127){
                higher = true;
            }
            else{
                lower = true;
            }
            if (higher){
                if (ravg < 127 || bavg < 127){
                    imageRGB[i][j][0] = 0;
                    imageRGB[i][j][1] = 0;
                    imageRGB[i][j][2] = 0;
                }
                else{
                    imageRGB[i][j][0] = 255;
                    imageRGB[i][j][1] = 255;
                    imageRGB[i][j][2] = 255;
                }
            }
            else{
                if (ravg > 127 || bavg > 127){
                    imageRGB[i][j][0] = 0;
                    imageRGB[i][j][1] = 0;
                    imageRGB[i][j][2] = 0;
                }
                else{
                    imageRGB[i][j][0] = 255;
                    imageRGB[i][j][1] = 255;
                    imageRGB[i][j][2] = 255;
                }

            }
        }
    }

}
//---------------------------------------------------------------------
void saveImage (){
    char output[100];
    cout << "\nEnter the output image file name: ";
    cin >> output;
    strcat (output, ".bmp");
    writeRGBBMP(output ,imageRGB);
}
//---------------------------------------------------------------------
