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
int main() {
	int n;
	int l, r;
	cin >> n;
	r = n-1;
	l = 0;
	string s;
	cin >> s;
	if (s.size() <= 2 ) {
		cout << s << endl;
		return 0;
	}
	int i = s.size()-1;
	string res = s;
	while (r != l && l < r) {
		res[r--] = s[i--]; 
		res[l++] = s[i--]; 
	}
	if (r == l) 
	res[r] = s[i];
	cout << res << endl;
	return 0;
}
