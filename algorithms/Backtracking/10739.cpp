#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];

int f(string s, int l, int r){
	
	if(l >= r) return 0;
	
	if(dp[l][r]!=-1) return dp[l][r];
	
    if(s[l] == s[r]) return dp[l][r] = f(s, l+1, r-1);   //os dois sao iguais
	
	int add = f(s, l+1, r-1)+1;
	int reE = f(s, l+1, r)+1;                 //removo da esquerda
	int reD = f(s, l, r-1)+1;                 //removo da direita
	return dp[l][r] = min(add, min(reD, reE));
}

int main (){
	int cont=1;
	string s;
	int o; cin>>o;
	while(o--){
		cin>> s;
		memset(dp,-1, sizeof dp);
		cout << "Case " << cont << ": " << f(s, 0, s.size()-1) << endl;
		cont++;
	}
}
