#include <bits/stdc++.h>

using namespace std;

#define s second
#define f first

int main(){
	
	int o;
	int target;
	int x;
	while(cin>>o){

		vector<int>vec;
		for(int i=0; i<o; i++){
			cin >> x; vec.push_back(x);
		}
		sort(vec.begin(), vec.end());
		cin >> target;
		
		vector<pair<int,pair<int,int>>>ans;
		vector<int>::iterator it;
		for(int i=0; i<o-1; i++){
			
			it = lower_bound(vec.begin()+(i+1), vec.end(), (target-vec[i]));
			
			if(*it + vec[i] == target){
				ans.push_back({abs(vec[i]-(*it)),{vec[i], (*it)}});//nao precisava guardar tudo era so perguntar se o first eh menor
			}
		}
		sort(ans.begin(), ans.end());
		
		cout << "Peter should buy books whose prices are " << ans[0].s.f << " and " << ans[0].s.s << "." << endl << endl;
	}
}
