#include <bits/stdc++.h>

using namespace std;

vector<long long int>vec;
int n, k;

long long int dp[200][20][1130];

long long int f(int x, long long int sum, int i){

  if(sum == n && x == k) return 1;
  if(i>(int)vec.size()) return 0;
  if(x > k || sum > n || vec[i]>n || x>=189) return 0;
  
  if(dp[i][x][sum]!=-1) return dp[i][x][sum];
  
  long long int take = f(x+1, sum+vec[i], i+1);
  long long int dtake = f(x, sum, i+1);
  
  return dp[i][x][sum] = take + dtake;
}

void sieve(int n){
  
  bool prime[n+1];
  memset(prime,true,sizeof prime);
  for(int p=2; p*p<=n; p++){
    if(prime[p]){
      for(int i=p*p; i<=n; i+=p)
        prime[i]=false;
    }
  }
  for(int i=2; i<=n; i++){
    if(prime[i]){
      vec.push_back(i);
    }
  }
}

signed main(){
  
  sieve(1130);
  cin>>n>>k;
  while(n || k){
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, 0) << endl;
    cin>>n>>k;
  }
}
