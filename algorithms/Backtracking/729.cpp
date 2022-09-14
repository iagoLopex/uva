#include <bits/stdc++.h>

using namespace std;

void perm(string ans, int x, int n, int cont){
	
	if(x == n){
		if(!cont)
			cout << ans << endl;
		return;
	}
	perm(ans+"0", x+1, n, cont);
	perm(ans+"1", x+1, n, cont-1);
}

int main(){
	
	int n,o,H;
	bool ok=false;
	cin >>o;
	while(o--){
		
		if(ok) cout << endl;
		ok=true;
		cin >> n >> H;
		perm("", 0, n, H);
	}
}
