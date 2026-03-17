#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#define X first
#define Y second

string board[101];
int dist[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> board[i]; // 미로 배열 받기
        }
    
    
    for(int i=0; i<n; i++){
        fill(dist[i], dist[i]+m,-1);
    }
 
    for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
            if(dist[i][j] != -1 || board[i][j] == '0') continue;
            dist[i][j] = 1;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                 
                    for(int i=0; i<4; i++){
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(dist[nx][ny] != -1  || board[nx][ny] != '1') continue;
                        dist[nx][ny] = dist[cur.X][cur.Y]+1;
                        Q.push({nx,ny});
                    }
                
            }
        }
    }
        cout << dist[n-1][m-1] << "\n";
    }
    




