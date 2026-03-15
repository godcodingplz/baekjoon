#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


void shift_left(list<int> &a, list<int>::iterator &b){
    if(b == a.begin()){
        return;
    }
    b--;
}

void shift_right(list<int> &a, list<int>::iterator &b ,int len){
    if(b == a.end()){
        return;
    }
    b++;
}

void list_delete(list<int> &a, list<int>::iterator &b ){
    if(b == a.begin()){
        return;
    }
    b--;
    b = a.erase(b);
 
}

void list_insert(list<int> &a, list<int>::iterator &b ,char c){
    a.insert(b, c);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    list<int> l;
    list<int>::iterator t = l.begin();
    
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        l.push_back(s[i]);
    }

    
    int len;
    cin >> len;
    for(int i=0; i<len; i++){
        char a;
        cin >> a;
        if(a == 'L'){
            shift_left(l,t);
        }
        else if(a == 'D'){
            shift_right(l,t,len);
        }
        else if (a == 'B'){
            list_delete(l,t);
        }
        else if(a == 'P'){
            char target;
            cin >> target;
            list_insert(l,t,target);
        }
    }
    for(list<int>::iterator it = l.begin(); it != l.end(); it++){
        cout << (char)*it;
    }
    return 0;
}

