#include <iostream>
#include <algorithm>
using namespace std;

int board[10];
bool check[10];

int n,m; // 전역변수 관리로 효율적으로 코딩할 수 있음 물론 코테에서
void func(int a){
    if(a == m){
        for(int i=0; i<m; i++){
            cout << board[i] << " " ;
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){
        if(check[i] == 0){
            board[a] = i;
            check[i] = 1;
            func(a+1);
            check[i] = 0; 
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
}
