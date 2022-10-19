#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string o;
    cin >> o;
    while(o!="0"){
        
        cout << "Original number was " << o << endl;
        map<string, int>mp;
        string x, y;
        int sub;
        int cont=0;
        
        bool ok = false;
        while(!ok){
            
            sort(o.begin(),o.end());
            x = o;
            sort(o.rbegin(),o.rend());
            y = o;
            
            sub = stoi(y) - stoi(x);
            
            cout << stoi(y) << " - " << stoi(x) << " = " << sub << endl;
            
            mp[to_string(sub)]++;
            
            if(mp[to_string(sub)] == 2) ok=true;
            
            o=to_string(sub);
            
            cont++;
        }
        cout << "Chain length " << cont << endl;
        cout << endl;
        cin >> o;
    }
    
}
