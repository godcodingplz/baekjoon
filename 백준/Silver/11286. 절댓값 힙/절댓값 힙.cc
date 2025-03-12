#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

struct cmp{
        bool operator()(int a, int b){
            if(abs(a) == abs(b)) return a > b;
            return abs(a) > abs(b);
        }    
    };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   

    priority_queue<int, vector<int>, cmp> queue;

    int N; cin >> N;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        if(x!=0){
            queue.push(x);
        }
        else if(x == 0){
            if(!queue.empty()){
                cout << queue.top() << '\n';
               int min = queue.top();
               queue.pop();               
            }
            else{
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}