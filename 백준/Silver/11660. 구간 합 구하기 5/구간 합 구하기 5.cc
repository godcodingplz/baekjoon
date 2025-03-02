#include <iostream>
#include <cstring>
using namespace std;

int arr[1026][1026];
int prefix[1026][1026];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    memset(prefix, 0, sizeof(prefix));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + arr[i][j];
        }
    }
    for(int i=0; i<M; i++){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
        cout << sum << "\n";
    }
    return 0;
}