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

    for(int j=0; j<str.length(); j++){
        if(str[j] == ' '){
            cipher += ' ';
            continue;
        }
        for(int i=0; i<26; i++){
            if(before[i] == tolower(str[j])){
                if(j==0 || str[j-1] == ' ') cipher += after[i];
                else if(j==str.length()-1 || str[j+1] == ' ') cipher += after[(i+6)%26];
                else cipher += after[(i+3)%26];
                break;
            }
        }
    }
    cout<<"After encryption: "<<cipher;
}
