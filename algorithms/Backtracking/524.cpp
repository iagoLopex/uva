#include <bits/stdc++.h>

using namespace std;
#define pb push_back

vector<int>vec;
bool vis[100];

bool isprime(int x){
    for(int i=2; i<=sqrt(x); i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

void permut(int x, int n){
	
	if(x == n && isprime(1+vec[n-1])){
		cout << vec[0];
		for(int i=1; i<n; i++){
			cout << " " << vec[i];
		}
		cout << endl;
		return;
	}
	for(int i=1; i<=n; i++){
		
		if(!vis[i] && isprime(i+vec[x-1])){
			vec.pb(i);
			vis[i]=true;
			permut(x+1, n);
			vis[i]=false;
			vec.pop_back();
		}
	}
}

int main(){
	
	int n, dale=0;
	bool a=false;
	while(cin>>n){	
		
		if(a){
			cout << endl;	
		}
		a=true;
		dale++;
		memset(vis, false, sizeof vis);
		vec.clear();
		vec.pb(1);
		vis[1]=true;
		cout << "Case " << dale << ":\n";
		permut(1, n);
	}
}
