#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];

string a, b;

int f(int i, int j){
	
	
	if(i==(int)a.size()) return b.size()-j;
	if(j==(int)b.size()) return a.size()-i;
	
	if(a[i] == b[j]) return dp[i][j] = f(i+1, j+1);
	
	if(dp[i][j]!=-1) return dp[i][j];
	
	int r = f(i, j+1);
	int aa = f(i+1, j);
	int t = f(i+1, j+1);
	
	return dp[i][j] = min(min(aa,t), r)+1;
}

int main(){
	
	int t;
	while(cin >> t >> a){
		cin >> t >> b;
		memset(dp, -1, sizeof(dp));
		cout << f(0, 0) << endl;
	}
}
