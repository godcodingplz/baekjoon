#include <iostream>
#include <vector>
using namespace std;

vector<int> calculate(int &N, int &count){
    vector<bool> is_prime(N+1, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;

    for(int i=2; i<=N; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j= i*2; j<=N; j+= i){
                is_prime[j] = false;
            }
        }
    }
    if(is_prime[N]){
        count++;
    }
    return primes;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int target; cin >> target;

    int start = 0; int end = 0;
    int count = 0; int sum = 0;

    vector<int> primes = calculate(target, count);

    
    while(end < primes.size()){
       if(sum < target){
            sum += primes[end];
            end++;
       }
       else{
           if(sum == target){
               count++;
           }
           sum -= primes[start];
           start++; 
       }
    
    }
    cout << count << '\n';
    return 0;
}