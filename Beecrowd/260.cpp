#include <bits/stdc++.h>

using namespace std;

char mat[205][205];
int vis[205][205];
int n;

int dx[]={0,1,0,-1,1,-1};
int dy[]={1,0,-1,0,1,-1};

void flood(int ax, int ay){
	
	vis[ax][ay] = 1;
	
	for(int i=0; i<6; i++){
		
		int bx = ax + dx[i];
		int by = ay + dy[i];
		
		if(bx>=0 && bx<n && by>=0 && by<n && !vis[bx][by] && mat[bx][by] == 'w'){
			flood(bx, by);
		}
	}
}

int main(){
	
	string a;
	int i, j, cont=0;
	cin >> n;
	while(n){
		
		cont++;
		memset(vis, 0, sizeof vis);
		for(i=0; i<n; i++){
			
			cin >> a;
			
			int tam = a.size();
			for(j=0; j<tam; j++){
				
				mat[i][j]=a[j];
			}
		}
		
		j=0;
		for(i=0; i<n; i++){				
			if(mat[i][j] == 'w'){
				flood(i, j);
			}
		}
		bool h = false;
		for(i=0; i<n; i++){
			if(vis[i][n-1]) h=true;
		}
		if(h) cout << cont <<  " W\n";
		else cout << cont <<" B\n";
		
		cin >> n;
	}
}
