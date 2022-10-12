#include <bits/stdc++.h>

using namespace std;

vector<int>vec;
vector<int>ans;
vector<vector<int>>guard;
int best;
int ind;
int target, n;
bool ok;

void func(int i, int sum){
	
	if(i==(int)vec.size()){

		if(sum == target && !ok){
			ok=true;
			for(int k=0; k<(int)ans.size(); k++){
				cout << ans[k] << " ";
			}
			cout << "sum:" << sum << endl;
		}
		else{
			if(sum < target){
				if(best<sum){
					best=sum;
					guard.push_back(ans);
					ind++;
				}
			}
		}
		
		return;
	}
	ans.push_back(vec[i]);
	func(i+1, sum+=vec[i]);
	ans.pop_back();
	func(i+1, sum-=vec[i]);
}

int main(){
	
	int a;
	while(cin >> target >> n){
		
		ok=false;
		ind=0;
		best=-1;
		while(n--){
			cin >> a;
			vec.push_back(a);
		}
		func(0, 0);
		if(!ok){
		  	for(int i=0; i<(int)guard[ (ind-1) ].size(); i++){
				cout << guard[ (ind-1) ][i] << " ";
			}
			cout << "sum:" << best << endl;
		}
		
		guard.clear();
		vec.clear();
		ans.clear();
	}
}
