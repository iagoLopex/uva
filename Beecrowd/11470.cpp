#include <bits/stdc++.h>

using namespace std;

int mat[102][102];
int vis[102][102];
int s;

void flood(int ax, int ay, int nn, int ii, int jj){
	
	vis[ax][ay]=true;
	
	if(ax == ii && ay+1<nn && !vis[ax][ay+1])
	{
		s+=mat[ax][ay+1];
		flood(ax, ay+1, nn, ii, jj);
	}
	
	if(ay == jj && ax+1<nn && !vis[ax+1][ay])
	{
		s+=mat[ax+1][ay];
		flood(ax+1, ay, nn, ii, jj);
	}
	
	if(ax == jj && ay-1>=0 && !vis[ax][ay-1])
	{
		s+=mat[ax][ay-1];
		flood(ax, ay-1, nn, ii, jj);
	}
	
	if(ay == ii && ax-1>=0 && !vis[ax-1][ay])
	{
		s+=mat[ax-1][ay];
		flood(ax-1, ay, nn, ii, jj);
	}
}

int main(){
	
	int n, i, j, dale=0, vem;
	
	cin >> n;
	while(n!=0){
		s=0;
		memset(vis, false, sizeof vis);
		int aux=n-1;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				cin >> mat[i][j];
			}
		}
		
		if(n%2){
			vem=(n+1);
		}
		else{
			vem=n;
		}
		
		dale++;
		cout << "Case " << dale << ":";
		for(i=0; i<vem/2; i++){
			s=0;
			s+=mat[i][i];
			flood(i, i, n, i, aux);
			aux--;
			cout << " " << s;
		}
		cout << endl;
		
		cin >> n;
	}
}
