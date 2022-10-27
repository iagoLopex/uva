#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string str;
	string s;
	getline(cin, s);
	while(s!="DONE"){
		
		str="";
		for(int i=0; i<(int)s.size(); i++)
			if(isalpha(s[i]))
				str+=tolower(s[i]);
		string r = str;
		reverse(str.begin(), str.end());
		cout << (str!=r ? "Uh oh..\n" : "You won't be eaten!\n");		
		
		getline(cin, s);
	}
}
//inicio da jornada de string de IagoLopex
