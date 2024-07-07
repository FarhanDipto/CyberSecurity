#include<bits/stdc++.h>
using namespace std;

int main(){
    char before[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
            'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
            's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    
    char after[] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
            'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K',
            'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

    string str, cipher;
    cout<<"Input the normal text: ";
    getline(cin, str);
    cout<<endl<<"Before encryption: "<<str<<endl;

    for(int i=0; i<str.length(); i++){
        for(int j=0; j<26; j++){
            if(str[i] == before[j]){
                cipher += after[j];
            }
            else if (str[i] == ' ') {
                cipher += ' ';
                i++;
            }
        }
    }
    cout<<"After encryption: "<<cipher;

}