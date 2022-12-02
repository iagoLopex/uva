#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define tos to_string
#define inf 1000000000
#define pi 3.141592653589793
#define inf64 1000000000000000000
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

void dbg(){cerr<<endl;}
template<typename X, typename...Y> void dbg(X x, Y...y){cerr<<' '<<x; dbg(y...);}
#define debug(...) cerr<<"("<<#__VA_ARGS__<<"):", dbg(__VA_ARGS__), cerr<<endl

vector<pair<int,pair<int,int>>>adj;
vector<int>pai;

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t, n, e, a, b, p, cont=1; cin>>t;
    while(t--){
		cin>>n>>e;
		
		for(int i=0; i<n; i++)
			pai.pb(i);
		
		for(int i=0; i<e; i++){
			cin>>a>>b>>p;
			if(a!=b) adj.pb({p,{a,b}});
		}
		
		int ans=inf;
		sort(rall(adj));
		for(int i=0; i<(int)adj.size(); i++){
			
			int u = find(adj[i].s.f);
			int v = find(adj[i].s.s);
			int weight = adj[i].f;
			
			if(u != v){
				ans=min(ans, weight);
				pai[u] = v;
			}
		}
		cout << "Case #" << cont << ": " << ans << endl;
		cont++;
		
		pai.clear();
		adj.clear();
	}    
}
