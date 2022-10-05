#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[5][30000];
int coin[]={50, 25, 10, 5, 1};

ll func(int i, ll valor){
	
	if(valor == 0) return 1;
	if(i > 4 || valor < 0) return 0;
	if(dp[i][valor] != -1) return dp[i][valor];
	
	ll Dtake = func(i+1, valor);
	ll take = func(i, valor-coin[i]);
	
	return dp[i][valor] = Dtake+take;
}

int main(){
	int n;
	while(cin >> n){
		
		for(int i=0; i<5; i++)
			for(int j=0; j<=n; j++)
				dp[i][j]=-1;
		ll x = func(0, n);
		if(x == 1) cout << "There is only 1 way to produce " << n << " cents change.\n";
		else cout << "There are " << x << " ways to produce " << n << " cents change.\n";
		
	}
}
