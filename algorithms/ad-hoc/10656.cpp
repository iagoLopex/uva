#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//~ freopen("out.txt", "w", stdout);
	int o;
	cin>>o;
	while(o){
		
		vector<int>ans;
		ans.push_back(0);
		for(int i=0; i<o; i++){
			int x;
			cin>>x;
			if(x) ans.push_back(x);
		}
		if((int)ans.size()==1){ cout << 0 << endl; }
		else{
			cout << ans[1];
			for(int i=2; i<(int)ans.size(); i++){
				cout << " " << ans[i];
			}
			cout << endl;
		}
		
		cin>>o;
	}
}
