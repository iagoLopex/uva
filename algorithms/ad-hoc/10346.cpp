#include <bits/stdc++.h>

using namespace std;

int main(){
	
	long long a, b;
	while(cin >> a >> b){	
		int ans=a;
		while(a>=b){
			ans+=(a/b);
			a=(a/b)+(a%b);
		}
		cout << ans << endl;
	}
}
