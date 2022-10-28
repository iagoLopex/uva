#include <bits/stdc++.h>

using namespace std;

vector<long long int> dp(60, -1);
long long int fib(long long int n){
	if(n==0) return dp[n] = 1;
	if(n==1) return dp[n] = 2;
	if(dp[n]!=-1)
		return dp[n];
	return dp[n]=fib(n-1)+fib(n-2);
}

void c(){ 
	for(int i=0; i<60; i++)  
		fib(i);
}

int main(){
	
	//freopen("out.txt", "w", stdout);
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
		
		vector<long long int>::iterator it;
		scanf(" ");
		getline(cin, s);
		string str="";
		string ans="";
		for(int i=0; i<50; i++) ans+="*";
		
		for(int i=0; i<(int)s.size(); i++){
			if((s[i]-0)>=65 && (s[i]-0)<=90)
				str+=s[i];
		}
		for(int i=0; i<(int)vec.size(); i++){
			it = upper_bound(dp.begin(), dp.end(), vec[i]);
			ans[ (it - dp.begin())-1 ] = str[i];
		}
		int id;
		for(int i=0; i<(int)ans.size(); i++){
			if(isalpha(ans[i])) id = i;
		}
		str="";
		for(int i=0; i<=id; i++){
			if(ans[i] == '*') str+=" ";
			else str+=ans[i];
		}
		cout << str << endl;
	}
}
