#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


string calculator(string a){
    stack<char> s;

    for(int i=0; i<a.size(); i++){
        if(a[i] == '(' || a[i] == '{' || a[i] == '['){
            s.push(a[i]);
        }
        else if(a[i] == ')' || a[i] == '}' || a[i] == ']'){
            if(a[i] == ')'){
                if(s.empty() || (s.top() != '(')) { // 앞이 참이면 뒤를 안봐서 empty일때 top하지 않음 굿!
                    return "no";
                }
                else{
                    s.pop();
                }
            }
            else if(a[i] == '}'){
                if(s.empty() || (s.top() != '{')) { 
                    return "no";
                }
                else{
                    s.pop();
                }
            }
            else if(a[i] == ']'){
                if(s.empty() || (s.top() != '[')) { 
                    return "no";
                }
                else{
                    s.pop();
                }
            }
        }
    }
    if(s.empty()){
    return "yes";
    }
    else{
        return "no";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while(1){
        getline(cin, s);

        if(s == "."){
            break;
        }

        cout << calculator(s) << '\n';
    }
    return 0;
}