#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int count=1;
    int n, m, x;
    cin>>n>>m;
    while(n||m){
        
        vector<int>vec;
        set<int>s;
        for(int i=0; i<n; i++){
            cin>>x;
            s.insert(x);
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        cout << "CASE# "<<count++<<":\n";
        for(int j=0; j<m; j++){
            cin>>x;
            if(!s.count(x))
                cout << x << " not found\n";
            else
                cout << x << " found at " << lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1 << endl;
        }
        cin>>n>>m;
    }
}
