#include <iostream>
#include <cmath>
using namespace std;

void calculate(char arr[], int start, int len){
    if(len == 1){
        return;
    }

    int mid = len/3;
    for(int i=start+mid; i<start+mid*2; i++){
        arr[i] = ' ';
    }
    calculate(arr,start,mid);
    calculate(arr,start+mid*2,mid);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n){
    int len = pow(3, n);
    char arr[len];
    for(int i=0; i<len; i++){
        arr[i] = '-';
    }
    calculate(arr, 0, len);
    for(int i=0; i<len; i++){
        cout << arr[i];
    }
    cout << "\n";
    }
    return 0;
}