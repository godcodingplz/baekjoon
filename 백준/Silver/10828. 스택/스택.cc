#include <iostream>
using namespace std;

int arr[10001];
int pos = 0;

void push(int x){
    arr[pos++] = x;
}

int pop(){
    if(pos == 0){
        return -1;
    }
    else{
        pos--;
        return arr[pos]; // pos-1 출력하는거 기억해라
    }
}

int size(){
    return pos;
}

int empty(){
    if(pos == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int top(){
    if(pos == 0){
        return -1;
    }
    else{
        return arr[pos-1];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    cin >> a;
    for(int i=0; i<a; i++){
        string b;
        cin >> b;
        if(b == "push"){
            int x;
            cin >> x;
            push(x);
        }
        else if(b == "top"){
            cout << top() << "\n";
        }
        else if(b == "pop"){
            cout << pop() << "\n";  
        }
        else if(b == "size"){
            cout << size() << "\n";
        }
        else if(b == "empty"){
            cout << empty() << "\n";
        }
     
    }
    return 0;
}

