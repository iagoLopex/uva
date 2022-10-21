#include <bits/stdc++.h>

using namespace std;

int main(){
	string x, y;
	while(cin >> x >> y){
		
		int k=0;
		for(int i=0; i<(int)y.size(); i++){
			if(x[k] == y[i]) k++;
		}
		cout << (k==(int)x.size() ? "Yes" : "No") << endl;
	}
}
