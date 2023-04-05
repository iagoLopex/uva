#include <bits/stdc++.h>
using namespace std;
int valor[100010];
int dp[10010][110];
int k;

int func(int i, int sum){
	
	if(i == 0) return !(sum%k);
	
	if(dp[i][sum]!=-1) return dp[i][sum];
	
	int add = func(i-1, (sum+valor[i-1])%k);
	int sub = func(i-1, (sum-valor[i-1])%k);
	
	return dp[i][sum] = add or sub;
}

int main()
{
	int o, n;
	cin >> o;
	while(o--){
		
		cin >> n >> k;
		memset(dp, -1, sizeof dp);
		for(int i=0; i<n; i++){
			cin >> valor[i];
		}
		cout << (func(n, 0) ? "Divisible" : "Not divisible") << endl;
	}
}
