#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int dist[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    queue<int> Q;
    Q.push(n);
    fill(dist, dist+100001, -1);
    dist[n] = 0;
   
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur < 0 || cur >= 100001) continue;
        if(cur == k){
            cout << dist[cur] << "\n";
            return 0;
        }
        if(cur + 1 < 100001 && dist[cur + 1] == -1){
            dist[cur + 1] = dist[cur] + 1;
            Q.push(cur+1);
        }
        if(cur - 1 >= 0  && dist[cur - 1] == -1){
            dist[cur - 1] = dist[cur] + 1;
             Q.push(cur-1);
        }
        if(cur*2 < 100001  && dist[cur*2] == -1){
            dist[2*cur] = dist[cur] + 1;
            Q.push(2*cur);
        }
    }
    return 0;
}