#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<char>> matrix(10, vector<char>(10, 'x'));

    int count=0, lastRow=0;
    string str, cipher, key;
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

    // string sortedKey = key;
    // vector<int> positions;

    // transform(sortedKey.begin(), sortedKey.end(), sortedKey.begin(), ::tolower);
    // sort(sortedKey.begin(), sortedKey.end());

    // for (char c : key) {
    //     if (isalpha(c)) {
    //         char letter = tolower(c);
    //         positions.push_back(sortedKey.find(letter) + 1);
    //     }
    // }


    for(int i=0; i<=lastRow; i++){
        for(int j=0; j<key.length(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout << endl;
    }

    // int columnCount = matrix[0].size();
    // vector<int> order(columnCount);

    // // Generating the order of column indices based on the key
    // for (int i = 0; i < columnCount; ++i) {
    //     order[i] = i + 1;
    // }

    // sort(order.begin(), order.end(), [&key](int a, int b) {
    //     return key[a - 1] < key[b - 1];
    // });

    // vector<vector<char>> temp(matrix.size(), vector<char>(matrix[0].size()));

    // // Previous code...

    // // Swapping columns in the matrix based on the key
    // for (int i = 0; i < columnCount; ++i) {
    //     int index = order[i] - 1;
    //     for (size_t j = 0; j < matrix.size(); ++j) {
    //         temp[j][i] = matrix[j][index];
    //     }
    // }

    // cout << "After swapping:" << endl;
    // for (int i = 0; i <= lastRow; i++) {
    //     for (int j = 0; j < key.length(); j++) {
    //         cout << temp[i][j] << " ";  // Display the updated matrix after swapping
    //     }
    //     cout << endl;
    // }

    // // Further code...


    // for(char c:key){
    //     int col=c-'0'-1; 
    //     if (col>=0 && col<key.length()){
    //         for (int i=0; i<=lastRow; i++){
    //             cipher += matrix[i][col];
    //         }
    //     }
    // }

    for(int i=0; i<=lastRow; i++){
        for(char c:key){
            int col=c-'0'-1; 
            if (col>=0 && col<key.length()){
                cipher += matrix[i][col];
            }
        }
    }
    // int num = stoi(str);
    cout<<"After encryption: "<<cipher;

}