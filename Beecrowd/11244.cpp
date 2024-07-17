#include <bits/stdc++.h>
using namespace std;

char mat[102][102];
int vis[102][102];
int cont;

int dx[]={0, 1, -1, 0, 1, -1, -1, 1};
int dy[]={1, 0, 0, -1, 1, -1, 1, -1};

void flood(int ax, int ay, int nn, int mm){
	
	vis[ax][ay]=true;
	for(int k=0; k<8; k++){
		
		int bx = ax + dx[k];
		int by = ay + dy[k];
		
		if(bx>=0 && bx<nn && by>=0 && by<mm && !vis[bx][by] && mat[bx][by] == '*'){
			cont++;
			flood(bx, by, nn, mm);
		}
	}
}

int main(){
	
	string a;
	int n, m, i, j, tam, star;
	
	cin >> n >> m;
	while(n!=0 || m!=0){
		
		memset(vis, false, sizeof vis);
		for(i=0; i<n; i++){
			cin >> a;
			tam=a.size();
			for(j=0; j<tam; j++){
				mat[i][j]=a[j];
			}
		}
		star=0;
		for(i=0; i<n; i++){
			for(j=0; j<tam; j++){
				if(!vis[i][j] && mat[i][j] == '*'){
					cont=1;
					flood(i, j, n, m);
					if(cont==1) star++;
				}
			}
		}
		cout << star << endl;
		cin >> n >> m;
	}
}
