#include<bits/stdc++.h>
using namespace std;

int main(){
    char map[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                's', 't', 'u', 'v', 'w', 'x', 'y', 'z',  
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                ' ', ',', '.', ';', '?', '!'};

    int p, q, n, phi_n, e, d, k, PU, PR, tempInt;
    string cipher, plaintext, tempStr;
    char str[] = {};

    cout<<"Input the normal text: ";
    getline(cin, plaintext);
    cout<<"Enter two large prime numbers: ";
    cin>>p>>q;

    n = p*q;
    tempStr = to_string(n);
    tempInt = tempStr.length();
    phi_n = (p-1)*(q-1);

    for (e=2; e<phi_n; e++){
        if(__gcd(e, phi_n)==1) break;
    }
    cout<<e;
    // cout<<e;
    // for(k=1; k<9999; k++){
    //     d = (1+k*phi_n)/e;
    //     if(typeid(d) == typeid(int)) break;
    // }
    // cout<<d;
    for(k=1; k<1000; k++){
        d = (1 + k*phi_n) / e;
        if(d * e == 1 + k*phi_n) break;
    }

    cout<<"\nKey Setup: "<<endl;
    cout<<"Public key: {"<<e<<", "<<n<<"}"<<endl;
    cout<<"Private key: {"<<d<<", "<<n<<"}"<<endl;

    for(char c:plaintext){
        for (int i=0; i<sizeof(map); i++) {
            if (map[i] == c) {
                if (i < 10) {
                    cipher += '0' + to_string(i);
                } else {
                    cipher += to_string(i);
                }
                break;
            }
        }
    }
    cout<<"Converted text: "<<cipher<<endl;

    int x = tempInt-1;
    int numChunks = (cipher.length()+ x-1)/x; 

    string chunk[numChunks];

    for(int i=0; i<numChunks; i++){
        int length = min(x, static_cast<int>(cipher.length()) - i*x);
        chunk[i] = cipher.substr(i*x, length);
    }

    for(int i=0; i<numChunks; i++){
        int chunkValue = stoi(chunk[i]);
        int encryptedValue = 1;
        int decryptedValue = 1;

        for (int j=0; j<e; j++) {
            encryptedValue = (encryptedValue * chunkValue) % n;
        }
        for (int j=0; j<d; j++) {
            decryptedValue = (decryptedValue * encryptedValue) % n;
        }

        cout<<"M"<<i+1<<" = "<<chunk[i]<<"\t";
        cout<<"C"<<i+1<<" = "<<encryptedValue<<"\t";
        cout<<"P"<<i+1<<" = "<<decryptedValue<<endl;
    }
}