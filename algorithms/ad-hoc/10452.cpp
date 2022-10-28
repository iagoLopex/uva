#include <bits/stdc++.h>

using namespace std;

int vx[]={-1,0,0};
int vy[]={0,1,-1};

char mat[10][10];
bool vis[10][10];
string alf="IEHOVA#";

int h, n, m;
void flood(int i, int j){
	
	vis[i][j]=true;
	for(int k=0; k<3; k++){
		
		int tox = i + vx[k];
		int toy = j + vy[k];
		
		if(tox>=0 && tox<n && toy>=0 && toy<m && !vis[tox][toy]){
			
			if(mat[tox][toy]==alf[h]){
			
				if(h>0) cout << " ";
				if(k==0) cout << "forth";
				if(k==1) cout << "right";
				if(k==2) cout << "left"; 
				
				h++;
				mat[tox][toy]='@';
				flood(tox, toy);
			}
		}
	}
}

int main(){
	
	int o; cin>> o;
	while(o--){
		
		h=0;
		memset(vis, false, sizeof vis);
		pair<int,int>guard;
		cin>>n >> m;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>> mat[i][j];
				if(mat[i][j]=='@'){ guard={i,j}; }
			}
		}
		flood(guard.first, guard.second);
		cout << endl;
	}
	
}
