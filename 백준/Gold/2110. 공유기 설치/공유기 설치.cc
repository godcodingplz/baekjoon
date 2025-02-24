#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,c;
    cin >> n >> c;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int start = 1;
    int end = a[n-1] - a[0];
    int result = 0;
    while(start <= end){
        int cnt = 1;
        int pre_house = a[0];
        int mid = (start + end)/2;
        for(int i=1; i<n; i++){
            if(a[i] - pre_house >= mid){
                pre_house = a[i];
                cnt++;
            }
        }
        if(cnt >= c){
            result = max(result, mid);
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout << result;
    return 0;
}
