#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>adj;
stack<int>ans;
bool vis[110];

void dfs(int v){
	vis[v]=true;
	for(auto i: adj[v]){
		if(!vis[i])
			dfs(i);
	}
	ans.push(v);
}

int main(){
	
	int n,m, a, b;
	cin >> n >> m;
	while(n || m){
		
		adj = vector<vector<int>>(n);
		memset(vis, false, sizeof vis);
		for(int i=0; i<m; i++){
			cin >> a >> b;
			a--;
			b--;
			adj[a].push_back(b);
		}
	
		for(int i=0; i<n; i++){
			if(!vis[i]){
				dfs(i);
			}
		}
		
		cout << ans.top()+1; ans.pop();
		while(!ans.empty()){
			cout << " " << ans.top()+1;
			ans.pop();
		}
		cout << endl;
		cin >> n >> m;
	}
}

