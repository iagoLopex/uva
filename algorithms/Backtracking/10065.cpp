#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int n;
int value;
int coin[105];
pair<int,int> dp[105][10010][25];

pair<int,int> f(int at, int w, int x){
	
	if(at > n)
		return {(int)1e9,(int)1e9};
	if(w >= value)
		return {w, x};
		
	pair<int,int>&h = dp[at][w][x];
	if(h.f!=-1 && h.s != -1)
		return h;
		
		
	pair<int,int> passa = f(at+1, w, x);             //passa
	pair<int,int> pega = f(at+1, w+coin[at], x+1); //pega
	
	if(passa.f < pega.f){
		h = passa;
	}
	else{
		if(passa.f > pega.f){
			h = pega;
		}
		else{
			if(passa.s <= pega.s)
				h = passa;
			else 
				h = pega;
		}
	}
	
	return  h;
}

signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int o, w;
	cin>>o;
	while(o--){
		
		cin>>w>>n;
		
		for(int i=0; i<105; i++)
			for(int j=0; j<10010; j++)
				for(int k=0; k<25; k++)
					dp[i][j][k] = {-1,-1};
			
		for(int i=0; i<n; i++){
			cin>>coin[i];
		}
		value = w;
		
		pair<int,int> c = f(0, 0, 0);
		
		cout << c.f << ' ' << c.s << endl;
	}
	
}
