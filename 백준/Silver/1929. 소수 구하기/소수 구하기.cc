#include <iostream>
#include <vector>
using namespace std;
void calculator(int &a, int &b){
    vector<bool> check(b+1, true);
    check[0] = check[1] = false;
    for(int i=2; i<=b; i++){
        if(check[i] == true && i >= a){
            cout << i << '\n';
        }
        for(int j=i*2; j<=b; j+=i){
            check[j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b; cin >> a >> b;
    calculator(a,b);

    return(0);
}