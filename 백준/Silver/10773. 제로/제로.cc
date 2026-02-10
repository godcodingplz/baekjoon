#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> st;
    int a;
    cin >> a;
    for(int i=0; i<a; i++){
        int b;
        cin >> b;
        if(b == 0){
            st.pop();
        }
        else{
        st.push(b);
        }
    }
    int target = 0;
    
    while(!st.empty()){
        target += st.top();
        st.pop();
    }
    cout << target << "\n";
}