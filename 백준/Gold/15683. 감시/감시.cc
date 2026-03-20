#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second

int board[10][10];
int board_check[10][10];
vector<pair<int,int>> cctv_set;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void UPD(pair<int,int> a, int dir, int n, int m){
    dir %= 4;

    int x = a.X;
    int y = a.Y;
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    while(true){
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
            /*for(int i=0; i<n; i++){ // 디버깅 함수 이용 많이 해야돼~ 도움 많이 된다~~
                for(int j=0; j<m; j++){
                    cout << board_check[i][j];
                }
                cout << "\n";
            } 
            cout << "\n";*/
            return;
        }
        if(board[nx][ny] == 6){
            /*for(int i=0; i<n; i++){ // 디버깅 함수 이용 많이 해야돼~ 도움 많이 된다~~
                for(int j=0; j<m; j++){
                    cout << board_check[i][j];
                }
                cout << "\n";
            }    
            cout << "\n";*/
            return;
        } 
        if(board[nx][ny] != 0 || board[nx][ny] == 7) {
            nx += dx[dir];
            ny += dy[dir];
            continue; // 조건식을 뭐부터 해야되는지 잘 생각해야됌 벽을 먼저 검사 안하면 어캐될지 생각해보셈;
        }
          
        board_check[nx][ny] = 7;
        nx += dx[dir];
        ny += dy[dir];
    }
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
int cctv_count = 0;;
int n, m;
cin >> n >> m;
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cin >> board[i][j];
        if(board[i][j] != 0 && board[i][j] != 6){
            cctv_count++;
            cctv_set.push_back({i,j});
        }
    }
}
int mn = 100001;
for(int mask = 0; mask < (1 << (2*cctv_count)); mask ++){// 1 << n == 2^n 우리는 4k를 만들어야돼~
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            board_check[i][j] = board[i][j];
            }
    }
    int tmp = mask;
    for(int i=0; i<cctv_count; i++){
    int dir = tmp % 4;
    //cout << dir << "\n"; // 디버깅 함수 이용 많이 해야돼~ 도움 많이 된다~~
    tmp /= 4;
    if(board[cctv_set[i].X][cctv_set[i].Y] == 1){
        UPD(cctv_set[i],dir,n,m);
    }
    else if(board[cctv_set[i].X][cctv_set[i].Y] == 2){
        UPD(cctv_set[i],dir,n,m);
        UPD(cctv_set[i],dir+2,n,m);
    }
    else if(board[cctv_set[i].X][cctv_set[i].Y] == 3){
        UPD(cctv_set[i],dir,n,m);
        UPD(cctv_set[i],dir+1,n,m);
    }
    else if(board[cctv_set[i].X][cctv_set[i].Y] == 4){
        UPD(cctv_set[i],dir,n,m);
        UPD(cctv_set[i],dir+1,n,m);
        UPD(cctv_set[i],dir+3,n,m);
    }
     else if(board[cctv_set[i].X][cctv_set[i].Y] == 5){
        UPD(cctv_set[i],dir,n,m);
        UPD(cctv_set[i],dir+1,n,m);
        UPD(cctv_set[i],dir+2,n,m);
        UPD(cctv_set[i],dir+3,n,m);
    }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board_check[i][j] == 0)
                count++;
            }
    }
    mn = min(count, mn);
}

    cout << mn << "\n";
    return 0;


}