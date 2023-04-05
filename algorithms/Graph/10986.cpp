#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>>adj(20010);
int dist[20010];

void dijkstra(int v){
	
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({0,v});
	dist[v] = 0;
	
	while(!q.empty()){
		
		pair<int, int>u = q.top();
		q.pop();
		
		for(auto i : adj[u.second]){
			
			if(dist[i.second] > u.first + i.first){
				
				dist[i.second] = u.first + i.first;
				q.push({dist[i.second], i.second});
			}
		}
	}
}

int main(){


	int o, n, e, me, to, a, b, p, turn=1;
	cin >> o;
	while(o--){
		
		cin >> n >> e >> me >> to;
		adj = vector<vector<pair<int,int>>>(n);
		
		for(int i=0; i<=n; i++){
			dist[i]=90000;
			//cout << dist[i] << endl;
		}
		
		
		for(int i=0; i<e; i++){
			cin >> a >> b >> p;
			adj[a].push_back({p, b});
			adj[b].push_back({p, a});
		}
	
		dijkstra(me);
		
		cout << "Case #" << turn << ": ";
		if(dist[to] == 90000){
			cout << "unreachable\n";
		}
		else{
			cout << dist[to] << endl;
		}
		
		turn++;
	}
}
