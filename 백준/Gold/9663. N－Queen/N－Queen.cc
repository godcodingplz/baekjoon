#include <iostream>
#include <algorithm>
using namespace std;

bool isused1[30];
bool isused2[30];
bool isused3[30];
int n;
int cnt=0;

void func(int a){
    if(a == n){
       cnt++;
    return;
    }
    for(int i=0; i<n; i++){
        if(isused1[i] != 0 || isused2[i+a] != 0 || isused3[a-i+n-1] != 0)continue;
        isused1[i] = 1;
        isused2[i+a] = 1;
        isused3[a-i+n-1] = 1;
        func(a+1);
        isused1[i] = 0;
        isused2[i+a] = 0;
        isused3[a-i+n-1] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);

    cout << cnt << "\n";
}