#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int dist[10005];

vector<vector< pair<int,int> >> adj;

void dijkstra(int v){
	
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
	q.push({0, v});
	dist[v]=0;
	
	while(!q.empty()){
		
		pair<int,int>u = q.top();
		q.pop();
		
		if(u.first > dist[u.second]) continue;
		
		for(auto i: adj[u.second]){
			
			if(dist[i.second] > i.first + u.first){
				
				dist[i.second] = u.first + i.first;
				q.push({dist[i.second],i.second});
			}	
		}
	}
}

int main(){
	
	int l, v, e, i, a, b, p, o, d;
	cin >> l;
	while(l--){
		cin >> v >> e;
		adj = vector<vector< pair<int,int> >> (v); 
		for(i=0; i<e; i++){
			cin >> a >> b >> p;
			a--;
			b--;
			adj[a].push_back({p,b});
		}	
		memset(dist, INF, sizeof dist);
		cin >> o >> d;
		dijkstra(--o);
		if(dist[--d] == INF) cout << "NO\n";
		else cout << dist[d] << endl;
	}
}
