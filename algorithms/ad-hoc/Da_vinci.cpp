#include <bits/stdc++.h>

using namespace std;

long long int dp[60];
long long int fib(long long int n){
	if(n<=1) return dp[n] = n;
	if(dp[n]!=-1)
		return dp[n];
	return dp[n]=fib(n-1)+fib(n-2);
}

void c(){ 
	for(int i=0; i<53; i++)  
		fib(i);
}

int main(){
	
	memset(dp, -1, sizeof dp);
	c();
	string s;
	int n, x;
	int o; 
	cin>>o;
	while(o--){
		
		cin>>n;
		vector<int>vec;
		for(int i=0; i<n; i++){
			cin>> x; vec.push_back(x);
		}
		
		vector<int>::iterator it = lower_bound(vec.begin(), vec.end(), 2);
		cout << *it << endl;
		
		cin.ignore();
		getline(cin, s);
		string str="";
		string ans="";
		for(int i=0; i<(int)s.size(); i++){
			if((s[i]-0)>=65 && (s[i]-0)<=90)
				str+=s[i];
			ans+="*";
		}
		//inicio
		for(int i=0; i<(int)str.size(); i++)
			ans[]=
			
	}
	
}
