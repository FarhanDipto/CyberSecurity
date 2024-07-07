#include<bits/stdc++.h>
using namespace std;

int IP[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

int IIP[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};

int PC1[56] = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12,4
};

int PC2[48] = {
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};


int NoOfShifts[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

int E_bit[48] = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
};

int Permutation_P[32] = {
    16, 7, 20, 21,
    29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31, 10,
    2, 8, 24, 14,
    32, 27, 3, 9,
    19, 13, 30, 6,
    22, 11, 4, 25
};


int S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};
int S2[4][16] = {
    {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
    {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
    {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
    {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
};
int S3[4][16] = {
    {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
    {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
    {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
    {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
};
int S4[4][16] = {
    {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
    {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
    {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
    {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
};
int S5[4][16] = {
    {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
    {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
    {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
    {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
};
int S6[4][16] = {
    {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
    {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
    {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
    {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
};
int S7[4][16] = {
    {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
    {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
    {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
    {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
};
int S8[4][16] = {
    {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
    {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
    {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
    {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
};

int key[64] = {
    0, 0, 1, 1, 0, 1, 0, 0,
    0, 0, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 1,
    1, 1, 0, 1, 1, 0, 1, 1,
    1, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0
};

int XORblock[64] = {
    1, 0, 1, 1, 1, 1, 0, 0,
    1, 1, 1, 0, 1, 0, 1, 1,
    0, 1, 0, 0, 0, 1, 0, 0,
    1, 1, 0, 1, 0, 0, 1, 1,
    1, 0, 1, 1, 0, 0, 0, 1,
    0, 1, 0, 0, 1, 1, 0, 1,
    0, 0, 1, 1, 1, 0, 0, 0,
    1, 1, 0, 0, 1, 0, 0, 1
};

const int ROWS = 8;
const int COLS = 8;
int plainTextArr[64];
int resultArr[64];
int display[64];
int XORtempArr[64];


void textToBinaryArray(const char* plainText, bitset<COLS> binaryArray[ROWS])
{
    int len = strlen(plainText);
    for (int i = 0; i < len; i++){

        int asciiValue = static_cast<int>(plainText[i]);
        bitset<8> binaryRepresentation(asciiValue);
        for (int j = 0; j < COLS; j++){
            binaryArray[i][COLS - 1 - j] = binaryRepresentation[j];
        }
    }
    for (int i = len; i < ROWS; i++){
        binaryArray[i] = bitset<COLS>(string("00000001"));
    }

    int count=0;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            plainTextArr[count]=binaryArray[i][j];
            count++;
        }

    }

    int count2=0;
    cout << "Converted into 64-bit block: " << endl;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            cout << plainTextArr[count2] << " ";
            count2++;
        }
        cout << endl;
    }
}

int main(){
	string plainText;
    cout<<"Enter an 8-character (or less) plaintext: ";
    getline(cin, plainText);
	cout<<endl;

    bitset<COLS> binaryArray[ROWS];
	textToBinaryArray(plainText.c_str(), binaryArray);
    int array3[56];
    for(int i=0; i<56; i++){
        int count=PC1[i]-1;
        array3[i]=key[count];
    }

    int arrayy[48];
	int key16[16][48];
    int array4[56];
	int array5[48];

    for(int i=0; i<16; i++){
        int count=NoOfShifts[i];
        for(int j=0; j<count; j++){
            array4[27]=array3[0];
            for(int m=0; m<27; m++){
                array4[m]=array3[m+1];
            }
            array4[55]=array3[28];
            for(int n=28; n<55; n++){
                array4[n]=array3[n+1];
            }
            for(int o=0; o<56; o++){
                array3[o]=array4[o];
            }
        }

        for(int m=0; m<56; m++){
            int count=PC2[m]-1;
            key16[i][m]=array4[count];
        }
    }

	cout<<endl;
	cout<<"Given key: "<<endl;
    int count = 0;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            cout << key[count] << " ";
            count++;
        }
        cout << endl;
    }

	cout<<endl;
    cout<<"Generated keys: "<<endl;
    int count2=0;
    for (int i = 0; i < 16; i++){
        cout<<"Key"<<i+1<<" : ";
        for (int j = 0; j <48; j++){
            cout << key16[i][j] << " ";
            count2++;
        }
        cout << endl;
    }
    cout<<endl;

    cout<<"Encryption started"<<endl;

    for(int i=0; i<64; i++) {
        resultArr[i] = 1;
        display[i] = 1;
        XORtempArr[i] = 1;
    }
    for(int i=0; i<64; i++){
        if(plainTextArr[i]==XORblock[i]){
            plainTextArr[i]=0;
        }
        else{
            plainTextArr[i]=1;
        }
    }
    for(int round=0; round<16; round++){
        int array2[64];
        for(int i=0; i<64; i++){
            resultArr[i] = resultArr[i] ^ plainTextArr[i];
        }
        for(int i=0; i<64; i++){
            array2[i] = resultArr[i];
        }

        for(int i=0; i<64; i++){
            int count=IP[i]-1;
            array2[i]=plainTextArr[count];
        }

        int arrayl0[32];
        int arrayr0[32];
        for(int i=0; i<32; i++){
            arrayl0[i]=array2[i];
            arrayr0[i]=array2[32+i];
        }

        int arrayl1[32];
        for(int i=0; i<32; i++){
            arrayl1[i]=arrayr0[i];
        }

        int array6[48];
        for(int m=0; m<48; m++){
            int count=E_bit[m]-1;
            array6[m]=arrayr0[count];
        }

        for(int i=0; i<48; i++){
            if(array6[i]==key16[round][i]){
                array6[i]=0;
            }
            else{
                array6[i]=1;
            }
        }

        int ar2d[8][6];
        int count10=0;
        for(int i=0; i<8; i++){
            for(int j=0; j<6; j++){
                ar2d[i][j]=array6[count10];
                count10++;
            }
        }


        int roww=0;
        int coll=0;
        int prer0[8][4];
        for(int i=0; i<8; i++){
            if((ar2d[i][0]==0 && ar2d[i][5]==0) ){
                roww=0;
            }
            else if((ar2d[i][0]==0 && ar2d[i][5]==1) ){
                roww=1;
            }
            else if((ar2d[i][0]==1 && ar2d[i][5]==0) ){
                roww=2;
            }
            else if((ar2d[i][0]==1 && ar2d[i][5]==1) ){
                roww=3;
            }
            if((ar2d[i][1]==0) && (ar2d[i][2]==0) && (ar2d[i][3]==0) && (ar2d[i][4]==0)   ){
                coll=0;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==0) && (ar2d[i][3]==0) && (ar2d[i][4]==1)   ){
                coll=1;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==0) && (ar2d[i][3]==1) && (ar2d[i][4]==0)   ){
                coll=2;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==0) && (ar2d[i][3]==1) && (ar2d[i][4]==1)   ){
                coll=3;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==1) && (ar2d[i][3]==0) && (ar2d[i][4]==0)   ){
                coll=4;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==1) && (ar2d[i][3]==0) && (ar2d[i][4]==1)   ){
                coll=5;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==1) && (ar2d[i][3]==1) && (ar2d[i][4]==0)   ){
                coll=6;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==1) && (ar2d[i][3]==1) && (ar2d[i][4]==1)   ){
                coll=7;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==0) && (ar2d[i][3]==0) && (ar2d[i][4]==0)   ){
                coll=8;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==0) && (ar2d[i][3]==0) && (ar2d[i][4]==1)   ){
                coll=9;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==0) && (ar2d[i][3]==1) && (ar2d[i][4]==0)   ){
                coll=10;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==0) && (ar2d[i][3]==1) && (ar2d[i][4]==1)   ){
                coll=11;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==1) && (ar2d[i][3]==0) && (ar2d[i][4]==0)   ){
                coll=12;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==1) && (ar2d[i][3]==0) && (ar2d[i][4]==1)   ){
                coll=13;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==1) && (ar2d[i][3]==1) && (ar2d[i][4]==0)   ){
                coll=14;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==1) && (ar2d[i][3]==1) && (ar2d[i][4]==1)   ){
                coll=15;
            }


            int value=0;
            if(i==0){
                value= S1[roww][coll];
            }
            else if(i==1){
                value= S2[roww][coll];
            }
            else if(i==2){
                value= S3[roww][coll];
            }
            else if(i==3){
                value= S4[roww][coll];
            }
            else if(i==4){
                value= S5[roww][coll];
            }
            else if(i==5){
                value= S6[roww][coll];
            }
            else if(i==6){
                value= S7[roww][coll];
            }
            else if(i==7){
                value= S8[roww][coll];
            }

            if(value==0){
                prer0[i][0]=0;
                prer0[i][1]=0;
                prer0[i][2]=0;
                prer0[i][3]=0;
            }
            else if(value==1){
                prer0[i][0]=0;
                prer0[i][1]=0;
                prer0[i][2]=0;
                prer0[i][3]=1;
            }
            else if(value==2){
                prer0[i][0]=0;
                prer0[i][1]=0;
                prer0[i][2]=1;
                prer0[i][3]=0;
            }
            else if(value==3){
                prer0[i][0]=0;
                prer0[i][1]=0;
                prer0[i][2]=1;
                prer0[i][3]=1;
            }
            else if(value==4){
                prer0[i][0]=0;
                prer0[i][1]=1;
                prer0[i][2]=0;
                prer0[i][3]=0;
            }
            else if(value==5){
                prer0[i][0]=0;
                prer0[i][1]=1;
                prer0[i][2]=0;
                prer0[i][3]=1;
            }
            else if(value==6){
                prer0[i][0]=0;
                prer0[i][1]=1;
                prer0[i][2]=1;
                prer0[i][3]=0;
            }
            else if(value==7){
                prer0[i][0]=0;
                prer0[i][1]=1;
                prer0[i][2]=1;
                prer0[i][3]=1;
            }
            else if(value==8){
                prer0[i][0]=1;
                prer0[i][1]=0;
                prer0[i][2]=0;
                prer0[i][3]=0;
            }
            else if(value==9){
                prer0[i][0]=1;
                prer0[i][1]=0;
                prer0[i][2]=0;
                prer0[i][3]=1;
            }
            else if(value==10){
                prer0[i][0]=1;
                prer0[i][1]=0;
                prer0[i][2]=1;
                prer0[i][3]=0;
            }
            else if(value==11){
                prer0[i][0]=1;
                prer0[i][1]=0;
                prer0[i][2]=1;
                prer0[i][3]=1;
            }
            else if(value==12){
                prer0[i][0]=1;
                prer0[i][1]=1;
                prer0[i][2]=0;
                prer0[i][3]=0;
            }
            else if(value==13){
                prer0[i][0]=1;
                prer0[i][1]=1;
                prer0[i][2]=0;
                prer0[i][3]=1;
            }
            else if(value==14){
                prer0[i][0]=1;
                prer0[i][1]=1;
                prer0[i][2]=1;
                prer0[i][3]=0;
            }
            else if(value==15){
                prer0[i][0]=1;
                prer0[i][1]=1;
                prer0[i][2]=1;
                prer0[i][3]=1;
            }
        }

        int finalr0[32];
        int zz=0;
        for (int p=0; p<8; p++){
            for (int q=0; q<4; q++){
                finalr0[zz] = prer0[p][q];
                zz++;
            }
        }
        cout<<endl;

        int arrayfinalr02[32];
        for(int m=0; m<32; m++){
            int count=Permutation_P[m]-1;
            arrayfinalr02[m]=finalr0[count];
        }

        int arrayr1[32];
        for(int i=0; i<32; i++){
            if(arrayl0[i]==arrayfinalr02[i]){
                arrayr1[i]=0;
            }
            else{
                arrayr1[i]=1;
            }
        }

        for(int i=0; i<32; i++){
            resultArr[i]=arrayr1[i];
            resultArr[32+i]=arrayl1[i];
        }

        cout<<"Output for round "<< round+1<<":"<<endl;
        int count2=0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cout<<resultArr[count2]<<" ";
                count2++;
            }
            cout<<endl;
        }
        for(int i=0; i<64; i++){
            array2[i]=resultArr[i];
        }
    }

    for(int m=0; m<64; m++){
        int count=IIP[m]-1;
        display[m]=resultArr[count];
    }

	cout<<endl;
    cout<<"After encryption: "<<endl;
    count2=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout<<display[count2]<<" ";
            count2++;
        }
        cout<<endl;
    }

	cout<<endl;
    cout<<"Decryption started"<<endl;

    for(int i=0; i<64; i++){
        plainTextArr[i]=display[i];
        resultArr[i] = 1;
        display[i] = 1;
        XORtempArr[i] = 1;
    }

    for(int round=0; round<16; round++)    {
        int array2[64];
        for(int i=0; i<64; i++){
            int count=IP[i]-1;
            array2[i]=plainTextArr[count];
        }

        int arrayl0[32];
        int arrayr0[32];
        for(int i=0; i<32; i++){
            arrayl0[i]=array2[i];
            arrayr0[i]=array2[32+i];
        }
        int arrayl1[32];
        for(int i=0; i<32; i++){
            arrayl1[i]=arrayr0[i];
        }

        int array6[48];
        for(int m=0; m<48; m++){
            int count=E_bit[m]-1;
            array6[m]=arrayr0[count];
        }

        for(int i=0; i<48; i++){
            if(array6[i]==key16[round][i]){
                array6[i]=0;
            }
            else{
                array6[i]=1;
            }
        }

        int ar2d[8][6];
        int count10=0;
        for(int i=0; i<8; i++){
            for(int j=0; j<6; j++){
                ar2d[i][j]=array6[count10];
                count10++;
            }
        }

        int roww=0;
        int coll=0;
        int prer0[8][4];

        for(int i=0; i<8; i++){
            if((ar2d[i][0]==0 && ar2d[i][5]==0) ){
                roww=0;
            }
            else if((ar2d[i][0]==0 && ar2d[i][5]==1) ){
                roww=1;
            }
            else if((ar2d[i][0]==1 && ar2d[i][5]==0) ){
                roww=2;
            }
            else if((ar2d[i][0]==1 && ar2d[i][5]==1) ){
                roww=3;
            }


            if((ar2d[i][1]==0) && (ar2d[i][2]==0) && (ar2d[i][3]==0) && (ar2d[i][4]==0)   ){
                coll=0;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==0) && (ar2d[i][3]==0) && (ar2d[i][4]==1)   ){
                coll=1;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==0) && (ar2d[i][3]==1) && (ar2d[i][4]==0)   ){
                coll=2;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==0) && (ar2d[i][3]==1) && (ar2d[i][4]==1)   ){
                coll=3;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==1) && (ar2d[i][3]==0) && (ar2d[i][4]==0)   ){
                coll=4;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==1) && (ar2d[i][3]==0) && (ar2d[i][4]==1)   ){
                coll=5;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==1) && (ar2d[i][3]==1) && (ar2d[i][4]==0)   ){
                coll=6;
            }
            else if((ar2d[i][1]==0) && (ar2d[i][2]==1) && (ar2d[i][3]==1) && (ar2d[i][4]==1)   ){
                coll=7;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==0) && (ar2d[i][3]==0) && (ar2d[i][4]==0)   ){
                coll=8;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==0) && (ar2d[i][3]==0) && (ar2d[i][4]==1)   ){
                coll=9;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==0) && (ar2d[i][3]==1) && (ar2d[i][4]==0)   ){
                coll=10;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==0) && (ar2d[i][3]==1) && (ar2d[i][4]==1)   ){
                coll=11;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==1) && (ar2d[i][3]==0) && (ar2d[i][4]==0)   ){
                coll=12;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==1) && (ar2d[i][3]==0) && (ar2d[i][4]==1)   ){
                coll=13;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==1) && (ar2d[i][3]==1) && (ar2d[i][4]==0)   ){
                coll=14;
            }
            else if((ar2d[i][1]==1) && (ar2d[i][2]==1) && (ar2d[i][3]==1) && (ar2d[i][4]==1)   ){
                coll=15;
            }

            int value=0;
            if(i==0){
                value= S1[roww][coll];
            }
            else if(i==1){
                value= S2[roww][coll];
            }
            else if(i==2){
                value= S3[roww][coll];
            }
            else if(i==3){
                value= S4[roww][coll];
            }
            else if(i==4){
                value= S5[roww][coll];
            }
            else if(i==5){
                value= S6[roww][coll];
            }
            else if(i==6){
                value= S7[roww][coll];
            }
            else if(i==7){
                value= S8[roww][coll];
            }

            if(value==0){
                prer0[i][0]=0;
                prer0[i][1]=0;
                prer0[i][2]=0;
                prer0[i][3]=0;
            }
            else  if(value==1){
                prer0[i][0]=0;
                prer0[i][1]=0;
                prer0[i][2]=0;
                prer0[i][3]=1;
            }
            else  if(value==2){
                prer0[i][0]=0;
                prer0[i][1]=0;
                prer0[i][2]=1;
                prer0[i][3]=0;
            }
            else  if(value==3){
                prer0[i][0]=0;
                prer0[i][1]=0;
                prer0[i][2]=1;
                prer0[i][3]=1;
            }
            else  if(value==4){
                prer0[i][0]=0;
                prer0[i][1]=1;
                prer0[i][2]=0;
                prer0[i][3]=0;
            }
            else  if(value==5){
                prer0[i][0]=0;
                prer0[i][1]=1;
                prer0[i][2]=0;
                prer0[i][3]=1;
            }
            else  if(value==6){
                prer0[i][0]=0;
                prer0[i][1]=1;
                prer0[i][2]=1;
                prer0[i][3]=0;
            }
            else  if(value==7){
                prer0[i][0]=0;
                prer0[i][1]=1;
                prer0[i][2]=1;
                prer0[i][3]=1;
            }
            else  if(value==8){
                prer0[i][0]=1;
                prer0[i][1]=0;
                prer0[i][2]=0;
                prer0[i][3]=0;
            }
            else  if(value==9){
                prer0[i][0]=1;
                prer0[i][1]=0;
                prer0[i][2]=0;
                prer0[i][3]=1;
            }
            else  if(value==10){
                prer0[i][0]=1;
                prer0[i][1]=0;
                prer0[i][2]=1;
                prer0[i][3]=0;
            }
            else  if(value==11){
                prer0[i][0]=1;
                prer0[i][1]=0;
                prer0[i][2]=1;
                prer0[i][3]=1;
            }
            else  if(value==12){
                prer0[i][0]=1;
                prer0[i][1]=1;
                prer0[i][2]=0;
                prer0[i][3]=0;
            }
            else  if(value==13){
                prer0[i][0]=1;
                prer0[i][1]=1;
                prer0[i][2]=0;
                prer0[i][3]=1;
            }
            else  if(value==14){
                prer0[i][0]=1;
                prer0[i][1]=1;
                prer0[i][2]=1;
                prer0[i][3]=0;
            }
            else  if(value==15){
                prer0[i][0]=1;
                prer0[i][1]=1;
                prer0[i][2]=1;
                prer0[i][3]=1;
            }
        }

        int finalr0[32];
        int zz=0;
        for (int p=0; p<8; p++){
            for (int q=0; q<4; q++){
                finalr0[zz] = prer0[p][q];
                zz++;
            }
        }
        cout<<endl;

        int arrayfinalr02[32];
        for(int m=0; m<32; m++){
            int count=Permutation_P[m]-1;
            arrayfinalr02[m]=finalr0[count];
        }

        int arrayr1[32];
        for(int i=0; i<32; i++){
            if(arrayl0[i]==arrayfinalr02[i]){
                arrayr1[i]=0;
            }
            else{
                arrayr1[i]=1;
            }
        }

        for(int i=0; i<32; i++){
            resultArr[i]=arrayr1[i];
            resultArr[32+i]=arrayl1[i];
        }
        
        for(int i=0; i<64; i++){
            resultArr[i] = resultArr[i] ^ plainTextArr[i];
        }
        for(int i=0; i<64; i++){
            array2[i] = resultArr[i];
        }

        cout<<"Output for round "<< round+1<<":"<<endl;

        int count2=0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cout<<resultArr[count2]<<" ";
                count2++;
            }
            cout<<endl;
        }
        for(int i=0; i<64; i++){
            array2[i]=resultArr[i];
        }
    }

    for(int m=0; m<64; m++){
        int count=IIP[m]-1;
        display[m]=resultArr[count];
    }

    for(int i=0;i<64;i++){
        if(display[i]==XORblock[i]){
            display[i]=0;
        }
        else
        {
            display[i]=1;
        }
    }

	cout<<endl;
    cout<<"After decryption: "<<endl;
    int count3=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout<<display[count3]<<" ";
            count3++;
        }
        cout<<endl;
    }
}
