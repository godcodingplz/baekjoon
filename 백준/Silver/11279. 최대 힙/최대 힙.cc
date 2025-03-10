#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> queue;

    int n; cin>>n;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(x == 0){
            if(!queue.empty()){
                cout<<queue.top()<<'\n';
                queue.pop();
            }
            else{
                cout<<0<<'\n';
            }
        }
        else{
            queue.push(x);
        }
    }

    return 0;
}