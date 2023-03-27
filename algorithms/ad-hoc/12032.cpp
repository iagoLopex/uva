#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int>&vec, int n, int v){
	bool ans=true;
	int aux = 0;
	for(int i=0; i<n && ans; i++){
		
		if(vec[i]-aux > v || v < 0)
			ans = false;
		if(vec[i]-aux == v)
			v--;
				
		aux = vec[i];
	}
	return ans;
}

int main(){
	int o;
	int c = 0;
	cin>>o;
	while(o--){
		int n; cin>>n;
		vector<int>vec(n);
		for(int i=0; i<n; i++){
			cin>>vec[i];
		}
		int l = 1, r = 1e8;
		
		while(l<r){
			int mid = (l+r)/2;
			if(ok(vec, n, mid)){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
		cout << "Case " << ++c << ": " << r << endl;
	}
}
