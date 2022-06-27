#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, a, soma, x;
	cin >> n;
	while(n--){
		
		cin >> a;
		if(a == 1){
			cout << 1 << endl;
		}
		else{	
			soma=1;
			for(int i=1; i<=a; i++){
				x=i;
				(i%2 ? x+=1 : x+=2);
				soma += x;
			}
			cout << soma-x << endl;
		}
	}
}
