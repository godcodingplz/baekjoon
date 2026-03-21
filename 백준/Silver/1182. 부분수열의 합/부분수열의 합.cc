#include <iostream>
#include <algorithm>
using namespace std;

int board[20];
int n;
int cnt = 0;
int target;


void func(int a, int b){
    if(a == n){
        if(b == target){
            cnt++;
        }
        return;
    }
    func(a+1,b+board[a]); // b+= 하면 b값 자체가 바뀐다.. 제발 조심해 ㅜㅜ...
    func(a+1,b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> target;
    for(int i=0; i<n; i++){
        cin >> board[i];
    }

    func(0,0);
    if(target == 0){ // 공집합 조심해야돼..
        cnt--;
    }
    cout << cnt << "\n";
}