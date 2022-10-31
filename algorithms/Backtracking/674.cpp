#include <bits/stdc++.h>
 
using namespace std;

int price[]={1, 5, 10, 25, 50};
int dp[6][8000];

int f(int i, int sum, int M){
	
	if(i > 4 || sum<0 || sum>M) return 0;
	if(sum == 0) return 1;
	
	if(dp[i][sum] != -1) return dp[i][sum];
	
	int take = f(i, sum-price[i], M);
	int Dtake = f(i+1, sum, M);
	
	return dp[i][sum] = take + Dtake;
}

int main(){
	int o;
	while(cin>>o){
		for(int i=0; i<5; i++)
			for(int j=0; j<=o; j++)
				dp[i][j]=-1;
		cout << f(0, o, o) << endl;
	}
}
