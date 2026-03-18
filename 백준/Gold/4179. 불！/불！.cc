#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

string board[1001];
int firedist[1001][1001];
int jihundist[1001][1001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i ++){
        cin >> board[i];
        fill(firedist[i], firedist[i]+m, -1);
        fill(jihundist[i], jihundist[i]+m, -1);
    }


    queue<pair<int, int>> FQ; // 불에 대한 큐
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'F'){
                FQ.push({i,j});
                firedist[i][j] = 0;
            }
        }
    }
    while(!FQ.empty()){
        pair<int,int> cur = FQ.front(); FQ.pop();

        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != '.' || firedist[nx][ny] != -1) continue;
            FQ.push({nx,ny});
            firedist[nx][ny] = firedist[cur.X][cur.Y] + 1;
        }
    }
   
    queue<pair<int,int>> JQ; // 지훈이 큐 도망쳐~~
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'J'){
                JQ.push({i,j});
                jihundist[i][j] = 0;
            }
        }
    }

    while(!JQ.empty()){
        pair<int,int> cur = JQ.front(); JQ.pop();

        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << jihundist[cur.X][cur.Y] + 1 << "\n";
                return 0;
            }
            if(board[nx][ny] != '.' || jihundist[nx][ny] != -1 || (firedist[nx][ny] <= jihundist[cur.X][cur.Y]+1 && firedist[nx][ny] != -1)) continue;
            JQ.push({nx,ny});
            jihundist[nx][ny] = jihundist[cur.X][cur.Y] + 1;
        }
    }

    cout << "IMPOSSIBLE" << "\n";
    return 0; 
}