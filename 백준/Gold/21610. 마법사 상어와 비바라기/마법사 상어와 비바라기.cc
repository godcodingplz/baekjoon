#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int board[51][51] = {0};
int check[51][51] = {0};
vector <pair<int,int>> coordinate;
int dx[4] = {-1,1,1,-1};
int dy[4] = {-1,1,-1,1};

void move(int d, int s){

    // 이번 턴 check 초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            check[i][j] = 0;
        }
    }

    if(d ==1){
        for(int i=0; i<coordinate.size(); i++){
            int tmp = s;
            while(tmp--){
                if(coordinate[i].second -1 >= 1 )
                    coordinate[i].second = coordinate[i].second -1;
                else
                    coordinate[i].second = n;
            }
        }
    }

    if(d ==2){
        for(int i=0; i<coordinate.size(); i++){
            int tmp = s;
            while(tmp--){
                if(coordinate[i].first -1 >= 1 && coordinate[i].second -1 >= 1){
                    coordinate[i].first = coordinate[i].first -1;
                    coordinate[i].second = coordinate[i].second -1;
                }
                else if(coordinate[i].first -1 < 1 && coordinate[i].second -1 >= 1){
                    coordinate[i].first = n;
                    coordinate[i].second = coordinate[i].second -1;
                }
                else if(coordinate[i].first -1 >= 1 && coordinate[i].second -1 < 1){
                    coordinate[i].first = coordinate[i].first -1;
                    coordinate[i].second = n;
                }
                else{
                    coordinate[i].first = n;
                    coordinate[i].second = n;
                }
            }
        }
    }

    if(d ==3){
        for(int i=0; i<coordinate.size(); i++){
            int tmp = s;
            while(tmp--){
                if(coordinate[i].first -1 >= 1){
                    coordinate[i].first = coordinate[i].first -1;
                }
                else{
                    coordinate[i].first = n;
                }
            }
        }
    }

    if(d ==4){
        for(int i=0; i<coordinate.size(); i++){
            int tmp = s;
            while(tmp--){
                if(coordinate[i].first -1 >= 1 && coordinate[i].second +1 <= n){
                    coordinate[i].first = coordinate[i].first -1;
                    coordinate[i].second = coordinate[i].second +1;
                }
                else if(coordinate[i].first -1 < 1 && coordinate[i].second +1 <= n){
                    coordinate[i].first = n;
                    coordinate[i].second = coordinate[i].second +1;
                }
                else if(coordinate[i].first -1 >= 1 && coordinate[i].second +1 > n){
                    coordinate[i].first = coordinate[i].first -1;
                    coordinate[i].second = 1;
                }
                else{
                    coordinate[i].first = n;
                    coordinate[i].second = 1;
                }
            }
        }
    }

    if(d ==5){
        for(int i=0; i<coordinate.size(); i++){
            int tmp = s;
            while(tmp--){
                if(coordinate[i].second +1 <= n )
                    coordinate[i].second = coordinate[i].second +1;
                else{
                    coordinate[i].second = 1;
                }
            }
        }
    }

    if(d ==6){
        for(int i=0; i<coordinate.size(); i++){
            int tmp = s;
            while(tmp--){
                if(coordinate[i].first +1 <= n && coordinate[i].second +1 <= n){
                    coordinate[i].first = coordinate[i].first +1;
                    coordinate[i].second = coordinate[i].second +1;
                }
                else if(coordinate[i].first +1 > n && coordinate[i].second +1 <= n){
                    coordinate[i].first = 1;
                    coordinate[i].second = coordinate[i].second +1;
                }
                else if(coordinate[i].first +1 <= n && coordinate[i].second +1 > n){
                    coordinate[i].first = coordinate[i].first +1;
                    coordinate[i].second = 1;
                }
                else{
                    coordinate[i].first = 1;
                    coordinate[i].second = 1;
                }
            }
        }
    }

    if(d ==7){
        for(int i=0; i<coordinate.size(); i++){
            int tmp = s;
            while(tmp--){
                if(coordinate[i].first +1 <= n){
                    coordinate[i].first = coordinate[i].first +1;
                }
                else{
                    coordinate[i].first = 1;
                }
            }
        }
    }

    if(d ==8){
        for(int i=0; i<coordinate.size(); i++){
            int tmp = s;
            while(tmp--){
                if(coordinate[i].first +1 <= n && coordinate[i].second -1 >= 1){
                    coordinate[i].first = coordinate[i].first +1;
                    coordinate[i].second = coordinate[i].second -1;
                }
                else if(coordinate[i].first +1 > n && coordinate[i].second -1 >= 1){
                    coordinate[i].first = 1;
                    coordinate[i].second = coordinate[i].second -1;
                }
                else if(coordinate[i].first +1 <= n && coordinate[i].second -1 < 1){
                    coordinate[i].first = coordinate[i].first +1;
                    coordinate[i].second = n;
                }
                else{
                    coordinate[i].first = 1;
                    coordinate[i].second = n;
                }
            }
        }
    }

    // 비 내리기
    for(int i=0; i<coordinate.size(); i++){
       board[coordinate[i].first][coordinate[i].second]++;
    }

    // 물복사버그
    for(int i=0; i<coordinate.size(); i++){
        for(int j=0; j<4; j++){
            int nx = coordinate[i].first+dx[j];
            int ny = coordinate[i].second+dy[j];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n){
                if(board[nx][ny]!= 0){
                    board[coordinate[i].first][coordinate[i].second]++;
                }
            }
        }
    }

    // 이번 턴 구름 위치 체크
    for(int i=0; i<coordinate.size(); i++){
       check[coordinate[i].first][coordinate[i].second] = 1;
    }

    int count = coordinate.size();

    // 새 구름 생성
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] >= 2 && check[i][j] == 0){
                coordinate.push_back({i,j});
                board[i][j] -= 2;
            }
        }
    }

    // 이전 구름 제거
    for(int i=0; i<count; i++){
       coordinate.erase(coordinate.begin());
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }

    coordinate.push_back({n-1,1});
    coordinate.push_back({n-1,2});
    coordinate.push_back({n,1});
    coordinate.push_back({n,2});

    for(int i=0; i<m; i++){
        int d, s;
        cin >> d >> s;
        move(d, s);
    }

    int sum = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sum += board[i][j];
        }
    }

    cout << sum;
}