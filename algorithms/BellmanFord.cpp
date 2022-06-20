#include <bits/stdc++.h>

using namespace std;
#define INF 1e9-1000

vector<pair<int,pair<int, int>>>adj;
int dist[1010];
bool belzin(int n, int e ){
	dist[0]=0;
	for(int i=0; i<n-1; i++){
		
		for(int j=0; j<e; j++){
			
			int a=adj[j].second.first;
			int b=adj[j].second.second;
			int peso=adj[j].first;
			
			if(dist[a]!=INF && dist[b] > dist[a] + peso){
				dist[b] = dist[a] + peso;
			}
		}
	}
	
	for(int j=0; j<e; j++){
		
		int a = adj[j].second.first;
		int b = adj[j].second.second;
		int peso = adj[j].first;
		
		if(dist[a]!=INF && dist[b] > dist[a] + peso){
			return true;
		}
	}
	return false;
}

int main(){
	int o, n, e, a, b, p,i;
	cin >> o;
	while(o--){
		
		cin >> n >> e;
		adj.clear();
		memset(dist, INF, sizeof dist);
		for(i=0; i<e; i++){
			cin >> a >> b >> p;
			adj.push_back({p,{a,b}});
		}
		cout << (belzin(n,e) ? "possible\n" : "not possible\n");
	}
}
