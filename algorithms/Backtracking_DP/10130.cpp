#include <bits/stdc++.h>

using namespace std;

int obj;
int dp[1005][1005];

int knap(int *valor, int *peso, int at, int w){
	
	if(at==obj || w==0)
		return 0;
	
	if(dp[at][w] != -1)
		return dp[at][w];
	
	if(peso[at] > w)
		return dp[at][w] = knap(valor, peso, at+1, w);
	
	//i take the object and change the value
	int op1 = knap(valor, peso, at+1, w-peso[at]) + valor[at];
	//i don't take the object and i go away
	int op2 = knap(valor, peso, at+1, w);
	
	return dp[at][w] = max(op1, op2);
	
}

int main(){
	
	int o, people, soma, maxv;
	cin >> o;
	while(o--){
		
		cin >> obj;
		int price[obj], weight[obj];
		for(int i=0; i<obj; i++){
			cin >> price[i] >> weight[i];  
		}
		
		soma=0;
		
		//number of people
		cin >> people;
		for(int i=0; i<people; i++){
			
			memset(dp, -1, sizeof dp);
			cin >> maxv;
			//calculo o maximo que cada pessoa pode carregar
			//how i do that?
			soma += knap(price, weight, 0, maxv);
		}
		cout << soma << endl;
	}
}
