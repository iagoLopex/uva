#include <bits/stdc++.h>

using namespace std;

int cont, maior;
char maze[40][90];
bool vis[40][90];

int vx[]={0,1,0,-1};
int vy[]={1,0,-1,0};

void flood (int i, int j){
	
	maze[i][j]='#';
	vis[i][j]=true;
	for(int k=0; k<4; k++){
		
		int ax = i + vx[k];
		int bx = j + vy[k];
		
		if(ax>=0 && ax<cont-2 && bx>=0 && bx<maior && !vis[ax][bx]){
			flood(ax, bx);
		}
	}
}


int main(){
	
	//freopen("out.txt", "w", stdout);
	int o; cin >> o;
	cin.ignore();
	while(o--){
		
		string li;
		memset(maze, ' ', sizeof maze);
		memset(vis, false, sizeof vis);
		pair<int,int>guard;

		vector<int>coluna;
		cont=0;
		maior=-1;
		
		char f;
		getline(cin, li);
		f=li[0];
		while(f!='_'){
			
			coluna.push_back((int)li.size());
			maior = max((int)li.size(),maior);
			for(int j=0; j<(int)li.size(); j++){
				if(li[j]!=' '){ vis[cont][j]=true; maze[cont][j]=li[j]; }
				else maze[cont][j]=' ';
				if(li[j]=='*') guard={cont,j};
			}
			cont++;
			
			getline(cin, li);
			f=li[0];
		}
		
		//linha final
		coluna.push_back((int)li.size());
		for(int j=0; j<(int)li.size(); j++){
			maze[cont][j]=li[j];
		}
		cont++;
		
		flood(guard.first, guard.second);
		
		for(int i=0; i<cont; i++){
			for(int j=0; j<coluna[i]; j++){
				cout << maze[i][j];
			}
			cout << endl;
		}
	}
}
