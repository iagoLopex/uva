#include <bits/stdc++.h>

using namespace std;

int vet[20];
vector<int>vec;

void perm(int x, int n){
	
	if(vec.size() == 6){
		cout << vec[0];
		for(int i=1; i<6; i++)
			cout << " " << vec[i];
		cout << endl;
		return;
	}
	for(int i=x; i<n; i++){
		vec.push_back(vet[i]);
		perm(i+1, n);
		vec.pop_back();
	}
	
}

int main(){
	
	int o;
	bool flag=false;
	cin >> o;
	while(o){
		
		if(flag)cout << endl;
		flag=true;
		
		for(int i=0; i<o; i++){
			cin >> vet[i];
		}
		perm(0, o);
		vec.clear();
		cin >> o;
	}
}
