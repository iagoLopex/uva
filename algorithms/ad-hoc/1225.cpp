#include <bits/stdc++.h>

using namespace std;

int main()
{
	int o; cin>>o;
	while(o--){
		int n; cin>>n;
		string s, x;
		map<int,int>mp;
		for(int i=0; i<=9; i++) mp[i]=0;
		for(int i=1; i<=n; i++){
			s=to_string(i);
			for(int j=0; j<(int)s.size(); j++){
				x="";
				x = s[j];
				mp[stoi(x)]++;
			}
		}
		cout << mp[0];
		for(int i=1; i<=9; i++){
			cout << " " << mp[i];
		}
		cout << endl;
	}
}
