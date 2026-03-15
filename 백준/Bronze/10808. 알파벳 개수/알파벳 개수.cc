#include<iostream>
using namespace std;

string s;
int freq[26] = {};

int main(){
    cin >> s;

    for(auto c : s){
        freq[c-'a']++;
    }

    for(int i=0; i<26; i++){
        cout << freq[i] << "\n";
    }
    return 0;
}