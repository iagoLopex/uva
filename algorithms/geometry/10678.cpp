#include <bits/stdc++.h>

using namespace std;

int main(){
	
	double o, x, l, d, h;
	cin >> o;
	while(o--){
		cin >> l >> d;
		d = d/2;
		l = l/2;
		x = d-l;
		h = sqrt((d*d-l*l));
		cout << fixed << setprecision(3);
		cout << h*(l+x)*3.14159265359 << endl;
	}
	
}
