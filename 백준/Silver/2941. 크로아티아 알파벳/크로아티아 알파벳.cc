#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int target = s.length();
    for(int i=1; i< s.length(); i++){
        if(s[i] == '='){
            if(s[i-1] == 'c' || s[i-1] == 's'){
                 target = target -1;
            }
            else if(s[i-1] == 'z'){
                if(s[i-2] == 'd'){
                     target = target-2;
                     continue;
                }
                 target = target-1;
            }
        }
        
        else if(s[i] == '-'){
            if(s[i-1] == 'c' || s[i-1] == 'd'){
                target = target - 1;
            }
        }
        else if(s[i] == 'j'){
            if(s[i-1] == 'l' || s[i-1] == 'n'){
                target = target-1;
            }
        }
    }
    cout << target << endl;
}