#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];

int f(string a, string b, int i, int j){
	
	if(i==(int)a.size() || j==(int)b.size()) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(a[i] == b[j]) return dp[i][j] = 1 + f(a, b, i+1, j+1);
	
	int take1 = f(a, b, i+1, j);
	int take2 = f(a, b, i, j+1);
	
	return dp[i][j] = max(take1,take2);
}

int main(){
	
	string x, y;
	while(cin >> x >> y){
		memset(dp, -1, sizeof dp);
		cout << f(x, y, 0, 0) << endl;
	}
}
