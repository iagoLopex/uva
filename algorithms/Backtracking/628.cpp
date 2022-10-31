#include <bits/stdc++.h>
 
using namespace std;

vector<string>vec;

void f(vector<string> &path, string rules, int atr){
	
	if(atr >= (int)rules.size()){
		for(auto x : path) cout<<x;
		cout<<endl;
		return;
	}
	
	char p = rules[atr];
	if(p=='#'){
		for(int h=0; h<vec.size(); h++){
			path.push_back(vec[h]);
			f(path, rules, atr+1);
			path.pop_back();
		}
	}
	else{
		for(int k=0; k<10; k++){
			string aux=to_string(k);
			path.push_back(aux);
			f(path, rules, atr+1);
			path.pop_back();
		}
	}
}

int main(){
	
	string s;
	int o;
	while(cin>>o){
		vec.clear();
		for(int i=0; i<o; i++){
			cin>>s; vec.push_back(s);
		}
		int n;
		string rules;
		cin>>n;
		for(int i=0; i<n; i++){
			cout<<"--"<<endl;
			cin >> rules;
			vector<string>asd;
			f(asd, rules, 0);
		}
	}
}
