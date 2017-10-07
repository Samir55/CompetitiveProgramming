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
int k, n, m;
int ah, am;
int main () { 
	//~ freopen("input.txt", "r", stdin);
	cin >> k >> n >> m;
	ah = am = 0;
	int c = k;
	while (c--) {
		string s;
		cin >> s;
		lp(i, s.size()) {
			s[i] = tolower(s[i]);
		}
		if (s != "mars" ) am++;
		else ah++;	
	}
	int res = 0;
	if (am >= m) {
		am -= m;
	} else {
		res += (m - am);
		am = 0;
	}
	int left = am + ah;
	if (left < n) {
		res += (n - left);
	}
	cout << res << endl;
		
	return 0;
}
