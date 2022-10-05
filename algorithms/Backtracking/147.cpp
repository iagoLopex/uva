#include <bits/stdc++.h>

using namespace std;
long double n;

int coin[11]={10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long int dp[40010][12];

long long int func(int valor, int i){
	
	if(valor == 0) return 1;
	if(i > 10) return 0;
	if(dp[valor][i] != -1) return dp[valor][i];
	
	long long int take = 0;
	if((valor-coin[i])>=0) take = func( valor-coin[i], i );
	long long int Dtake = func( valor, i+1 );
	
	return dp[valor][i] = (take + Dtake);
}

int main(){

	cin >> n;
	long double k;
	while(n != 0){
		k=n;
		memset(dp, -1, sizeof dp);
		n*=10000;
		n/=100;
		
		cout << fixed << setprecision(2);
		cout << setw(6) << setfill(' ') << k;
		cout << setw(17) << setfill(' ') << func(n, 0) << endl;
		cin >> n;
	}
}
