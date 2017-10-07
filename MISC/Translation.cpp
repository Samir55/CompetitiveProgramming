#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
string m[] = {"CARS", "cars", "IuVEJxTXs", "UvOHhng", "yZKfAYmaqolM", "NtGQibw", "djPrCpek", "FWzL", "aySBaPyb", "RM", "gzYMynY"};
string h[] = {"Unil", "EPFL", "vpVZzBNtL", "SCubWma", "ocIYneAPqxDs", "hRkMGgJ", "fHrFUQTj", "XOwd", "PolyProg", "is", "awesome"};
int l = 11;

map<char, char> mtoh;
void construct() {
	lp(i, l) {
		lp(j, m[i].size()) {
			mtoh[m[i][j]] = h[i][j];
		}
	}
	mtoh['D']= 'K';
}

string convert(string s) {
	string ret = "";
	lp(i, s.size()) {
		if(s[i] != ' ' && mtoh.count(s[i]) <= 0) continue;
		if(s[i] == ' ') ret+=" ";
		else ret += mtoh[s[i]];
	}
	return ret;
}
	
int main () { 
	int n;
	cin >> n;
	construct();
	string s;
	while (n--) {
		cin >> s;
		cout << convert(s); 
		if (n >= 1) cout << " ";
	}
	cout << endl;
	return 0;
}
