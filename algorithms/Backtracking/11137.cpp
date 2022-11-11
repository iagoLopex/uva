#include <bits/stdc++.h>

using namespace std;

typedef long long int no;

vector<no>vec(21);
no dp[21][10000];

no f(no i, no sum){
	if(i >= 21 || sum<0) return 0;
	if(sum == 0) return 1;
	if(dp[i][sum]!=-1) return dp[i][sum];
	
	return dp[i][sum] = f(i, sum-vec[i]) + f(i+1, sum);
}

int main(){
	for(int i=1; i<=21; i++){
		vec[i-1] = i*i*i;
	}
	int n;
	while(cin>>n){
		memset(dp, -1, sizeof dp);
		cout << f(0, n) << endl;
	}
}
