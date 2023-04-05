#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[55][305][305];
vector<int>vec, point(305), x;

void show(){
	for(int i=0;i<k;i++)
		cout << x[i] << " \n"[i == k-1];
}

int f(int at, int sum, int qtd){
	
	if(sum==0){ 
		
		if(qtd < (int)x.size()){
			x = vec;
		}
		else{
			if(qtd == (int)x.size()){
				
				bool ok=false;
				for(int i=0; i<qtd && !ok; i++){
					if(x[i] < vec[i])
						ok=true;
				}
				
				if(ok)
					x = vec;
			}
		}
		
		return 0;
	}
	if(at==0 || sum<0) return 5000;
	
	int ans = f(at - 1, sum, qtd);
	
	if(point[at-1]<=sum && qtd <= (int)x.size()){
		vec.push_back(point[at-1]);
		ans = min(ans, f(at, sum-point[at-1], qtd+1) + 1);
		vec.pop_back();
	}
	
	return ans;
}

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int o, target, cont=0;
	cin>>o;
	while(o--){
		
		cin>>n>>target;
		for(int i=0; i<n; i++)
			cin>>point[i];
		
		x=point;
		
		k = f(n,target, 0);
		
		if(k==5000){
			cout << "Case " << ++cont << ": impossible" << endl;
		}
		else{
			cout << "Case " << ++cont << ": [" << k << "] ";
			show();
		}
	}
}
