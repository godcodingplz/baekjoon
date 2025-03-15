#include <iostream>
#include <vector>
using namespace std;

void binary_search(vector<int> &a, int target){
    int low = 0;
    int high = a.size()-1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(a[mid] == target){
            return;
        }
        else if(a[mid] < target){
            low = mid + 1;
        }
        else if(a[mid] > target){
            high = mid - 1;
        }
    }
   if(low < a.size()){
        a[low] = target;
   }
   else{
        a.push_back(target);
   }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A; cin>>A;
    vector<int> arr;

    for(int i=0; i<A; i++){
        int t; cin >> t;
        if(arr.empty()){    
            arr.push_back(t);
        }
        else{
            binary_search(arr, t);
        }
    }
   
        cout << arr.size() << '\n';

}