#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 1000000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int fi[1000001];

int rec(int x){
	
	if(x==0) return 1;
	if(fi[x]) return fi[x];
	return fi[x] = (rec(x-sqrt(x)) + rec(log(x)) + rec(x*sin(x)*sin(x)))%1000000;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int ind;
    cin >> ind;
    while(ind!=-1){
		cout << rec(ind) << endl;
		cin >> ind;
	}
}
