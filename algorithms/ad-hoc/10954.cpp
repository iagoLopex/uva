#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;cin >> n;
	int a;
	while(n){
		priority_queue<int, vector<int>, greater<int>>q;
		for(int i=0; i<n; i++){
			cin >> a;
			q.push({a});
		}
		int sum=0, ans=0;
		while(q.size()>1){
			sum+=q.top();
			q.pop();
			sum+=q.top(); q.pop();
			q.push(sum);
			ans+=sum;
			sum=0;
		}
		cout << ans << endl;
		cin >> n;
	} 
}
