#include <bits/stdc++.h>

using namespace std;
#define int long long

int dp[62][62];
string s;
int f(int l, int r){
	if(l>=r)
		return l==r;

	if(dp[l][r]!=-1)
		return dp[l][r];
	
	dp[l][r] = 0;
	if(s[l] == s[r])
		dp[l][r] += f(l+1, r-1)+1;
	
	dp[l][r] += f(l+1, r);
	dp[l][r] += f(l, r-1);
	dp[l][r] -= f(l+1, r-1);
	
	return dp[l][r]; 
}

signed main(){
	int n;cin>>n;
	while(n--){
		cin>>s;
		memset(dp, -1, sizeof dp);
		cout << f(0, s.size()-1) << endl;
	}
}
