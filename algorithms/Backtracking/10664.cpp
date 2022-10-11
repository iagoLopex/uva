#include <bits/stdc++.h>

using namespace std;

vector<int>vec;
int dp[21][203];
int tam;

int func(int i, int sum){
	
	if(i==tam) return sum;
	if(dp[i][sum]!=-1) return dp[i][sum];
	
	int take = func(i+1, sum+vec[i]);
	int Dtake = func(i+1, abs(sum-vec[i]));
	
	return dp[i][sum] = min(take, Dtake);
}

int main(){
	
	string a;
	int n; cin >> n;
	cin.ignore();
	while(n--){
		
		memset(dp, -1, sizeof dp);
		getline(cin,a);
		stringstream ss(a);
		string token;
		while(ss>>token){
			vec.push_back(stoi(token));
		}
		tam = vec.size();
		//~ tam--;
		cout << (func(0, 0) ? "NO\n" : "YES\n");
		vec.clear();
	}
}
