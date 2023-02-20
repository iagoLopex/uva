#include <bits/stdc++.h>
const double raio = 6371009;
const double pi = acos(-1.0);
using namespace std;

//formula de Haversine
double dist1(double r, double lat1, double lon1, double lat2, double lon2) {      // lenta e tem menos precisão
  double dlon = lon1 - lon2;
  return r * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(dlon));
}

int main(){
	
	double mela, melo, tola, tolo;
	double x1, y1, z1;
	double x2, y2, z2;
	int tt;cin>>tt;
	while(tt--){
		cin >> mela >> melo >> tola >> tolo;
		cout << fixed << setprecision(0);
		mela = (mela)*pi/180;
		melo = (melo)*pi/180;
		tola = (tola)*pi/180;
		tolo = (tolo)*pi/180;
		x1 = raio * cos( melo ) * cos( mela );
		y1 = raio * sin( melo ) * cos( mela );
		z1 = raio * sin( mela );
		
		x2 = raio * cos( tolo ) * cos( tola );
		y2 = raio * sin( tolo ) * cos( tola );
		z2 = raio * sin( tola );
		
		double a = sqrt(pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2));
		double b = dist1(raio, mela,  melo, tola, tolo);
		cout << abs(a - b) << endl;
	}
}
