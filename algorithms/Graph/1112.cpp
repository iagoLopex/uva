#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>>adj(105);
int dist[105];

void dijkstra(int v){
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
	q.push({0, v});
	dist[v] = 0;
	
	while(!q.empty()){
		
		pair<int,int>u = q.top();
		q.pop();
		
		if(u.first > dist[u.second]) continue;
		//cout << u.second << "\n";
		for(auto i : adj[u.second]){
			
			//cout << "eu to " << u.second << "   aonde vou " << i.second << " ||| "  << dist[i.second] << " " << i.first << " " << u.first << endl;  
			if(dist[i.second] > i.first + u.first){
				
				dist[i.second] = u.first + i.first;
				q.push({dist[i.second], i.second});
			}
		}		
	}
}

int main(){
	
	int o, a, b, p, exi, e, n, counter, cont;
	string lix;
	cin >> o;
	getline(cin, lix);
	while(o--){
		
		
		cin >> n >> exi >> counter >> e;
		for(int i=0; i<=n; i++){
		    dist[i] = INT_MAX;
		}
		
		for(int i=0; i<e; i++){
			cin >> a >> b >> p;
			adj[b].push_back({p,a});
		}
		dijkstra(exi);
		cont=0;
		
		//cout << endl << endl;
		for(int i=1; i<=n; i++){
		    //cout << i << "  " << dist[i] <<endl;
		    if(dist[i] <= counter){
		        cont++;
		    }
		}
		cout << cont << endl << endl;
		getline(cin, lix);
	}
}
