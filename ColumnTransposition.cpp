#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<char>> matrix(10, vector<char>(10, 'x'));
    vector<pair<int, int>> pos;

    int count=0, lastRow=0;
    string str, cipher, key, keyToPos;
    cout << "Input the normal text: ";
    getline(cin, str);
    cout << "Input the key: ";
    getline(cin, key);
    cout << endl << "Before encryption: " << str << endl;

    for(int i=0; i<10; i++){
        for(int j=0; j<key.length() && count<str.length(); j++){
            if(str[count] != ' '){
                matrix[i][j] = str[count];
                count++;
                lastRow=i;
            }
            else{
                j--;
                count++;
            }
        }
    }

    string sortedKey = key;
    vector<int> positions;

    transform(sortedKey.begin(), sortedKey.end(), sortedKey.begin(), ::tolower);
    sort(sortedKey.begin(), sortedKey.end());

    for (char c : key) {
        if (isalpha(c)) {
            char letter = tolower(c);
            positions.push_back(sortedKey.find(letter) + 1);
        }
    }

    for (int pos : positions) {
        keyToPos += to_string(pos);
    }

    for(int i=0; i<=lastRow; i++){
        for(int j=0; j<key.length(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout << endl;
    }

    cout<<"Order of alphabets in the key: "<<keyToPos<<endl;

    for (int i=0; i<keyToPos.length(); i++){
        pos.push_back({keyToPos[i] - '0', i});
    }
    sort(pos.begin(), pos.end());

    for (const auto& pos : pos){
        int col = pos.second;
        if (col >= 0 && col < keyToPos.length()) {
            for (int i = 0; i <= lastRow; ++i) {
                cipher += matrix[i][col];
            }
        }
    }
    // int num = stoi(str);
    // for(char c:keyToPos){
    //     int col=c-'0'-1; 
    //     if (col>=0 && col<keyToPos.length()){
    //         for (int i=0; i<=lastRow; i++){
    //             cipher += matrix[i][col];
    //         }
    //     }
    // }
    cout<<"After encryption: "<<cipher;
}