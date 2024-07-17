#include <bits/stdc++.h>

using namespace std;

char mat[101][101];
int vis[101][101];
int cont;

int dx[]={0, 1, -1, 0};
int dy[]={1, 0, 0, -1};

void flood(int ax, int ay, int nn){
	
	if(mat[ax][ay] == 'x' && !vis[ax][ay]){
		cont=1;
	}
	
	vis[ax][ay]=true;

	for(int k=0; k<4; k++){
		
		int bx = ax + dx[k];
		int by = ay + dy[k];
		
		if(bx>=0 && bx<nn && by>=0 && by<nn && !vis[bx][by] && (mat[bx][by] == '@' || mat[bx][by] == 'x')){
			flood(bx, by, nn);
		}
	}
}

int main(){
	
	string a;
	int o, n, i, j, tam, soma, dale=0;
	
	cin >> o;
	while(o--){
		
		soma=0;
		memset(vis, false, sizeof vis);
		cin >> n;
		for(i=0; i<n; i++){
			cin >> a;
			tam=a.size();
			for(j=0; j<tam; j++){
				mat[i][j]=a[j];
			}
		}
		for(i=0; i<n; i++){
			for(j=0; j<tam; j++){
				if(!vis[i][j] && (mat[i][j] == '@' || mat[i][j] == 'x')){
					cont=0;
					flood(i, j, n);
					soma+=cont;
				}
			}
		}
		dale++;
		cout << "Case " << dale << ": " << soma << endl;
	}
}
