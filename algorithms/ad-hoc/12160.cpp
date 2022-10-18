#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int dist[10010];

void bfs(int me, vector<int>&vec){	
	
	queue<int>q;
	q.push(me);
	dist[me]=0;
	
	while(!q.empty()){
		
		int u = q.front();
		q.pop();
		
		//cout << "entrou\n";
		//cout << "topo  " << u << endl;
		for(int i=0; i<(int)vec.size(); i++){
			
			int ax = (u + vec[i])%10000; 
			
			if(dist[ax] == -1){
				//cout << ax << endl;
				dist[ ax ] = dist[u] + 1;
				q.push(ax);
			}
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int cont=1;
	int k;
	cin >> a >> b >> c;
	while(a || b || c){
		
		vector<int>vec;
		memset(dist, -1, sizeof dist);
		for(int i=0; i<c; i++){
			cin >> k;
			vec.push_back(k);
		}
		bfs(a, vec);
		string x = to_string(dist[b]);
		cout << "Case " << cont << ": " << ((dist[b] == -1) ?  "Permanently Locked" : x) << endl;
		cont++;
		cin >> a >> b >> c;
	}
}
