#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[1001][1001];
int dist[1001][1001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;
    queue<pair<int,int>> Q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            dist[i][j] = -1;
            if(board[i][j] == 1){
                Q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] != -1 || board[nx][ny] == -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    
    int mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mx = max(dist[i][j], mx);
            if(dist[i][j] == -1 && board[i][j] == 0){
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << mx << "\n";
    return 0;
    
}      
           