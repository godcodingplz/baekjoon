#include<iostream>
using namespace std;

string s;


int main(){
    cin >> s;

    for(char a = 'a'; a<='z'; a++){
        int cnt = 0;
        for(auto c : s){
            if(a == c){
                cnt++;
            }
        }
        cout << cnt << ' ';
    }

    return 0;
}