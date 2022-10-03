#include <bits/stdc++.h>

using namespace std;

int tamPika[110];
int dp[110][50110];

int smallest(int i, int sum){
	
	if(i == 0){   //cheguei no ultimo elemento do vetor
		return sum; //retorno o o ultimo valor calculado
	}
	if(dp[i][sum]!=-1) return dp[i][sum];
	
	int take = smallest(i-1, abs(sum+tamPika[i-1]));  //eu peguei e passei
	int Dtake = smallest(i-1, abs(sum-tamPika[i-1])); //nao peguei e passei
	
	return dp[i][sum] = min(Dtake, take);
}

int main(){
	int o, n;
	cin >> o;
	while(o--){
		cin >> n;
		memset(dp, -1, sizeof dp);
		for(int i=0; i<n; i++){
			cin >> tamPika[i];
		}
		cout << smallest(n, 0) << endl;
	}
}
