#include <bits/stdc++.h>
	
using namespace std;
	
int main(){
	
	int o; cin>>o;
	while(o--){
		string s; cin>>s;
		string x = s;
		reverse(s.begin(),s.end());
		string ans;
		bool ok=false;
		int cont=0;
		while(!ok){
			
			long long int sum = stoul(x) + stoul(s);
            ans = to_string(sum);
			int k = ans.size();
			bool a=true;
			for(int i=0, j=k-1; i<(k/2); i++, j--){
				if(ans[i] != ans[j]) a=false;
			}
			if(a) ok=true;
			
			x = ans;
			s = ans;
			reverse(s.begin(), s.end());
			cont++;
		}
		cout << cont << " " << ans << endl;
	}
}
