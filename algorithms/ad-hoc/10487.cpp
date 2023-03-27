#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int cont=0;
	int n;
	cin>>n;
	while(n){
		
		vector<int>vec(n);
		for(int i=0; i<n; i++){
			cin>>vec[i];
		}
		sort(vec.begin(), vec.end());
		int q,a;
		cin>>q;
		cout << "Case " << ++cont << ":\n";
		for(int j=0; j<q; j++){
			cin>>a;
			int ans = 1e9;
			for(int i=0; i+1<n; i++){
				
				for(int k=i+1; k<n; k++){
					if(abs(a-ans) > abs(a - (vec[i]+vec[k]))){
						ans = vec[i]+vec[k];
					}
				}
			}
			
			cout << "Closest sum to " << a << " is " << ans << ".\n";
		}
		cin>>n;
	}
}
