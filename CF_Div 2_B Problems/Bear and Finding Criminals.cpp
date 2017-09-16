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
	int n, p;
	vector<int> t;
	cin >> n >> p;
	p--;
	while (n--) {
		int x;
		cin >> x;
		t.push_back(x);
	}
	int d = 1, res = 0; 
	int r = p+d, l = p-d;
	while (r < t.size() || l >= 0) {
		if (r < t.size() && l >= 0) {
			if (t[r] == t[l] && t[r]) {
				res += 2;
			}
		} else if ( r >= t.size() && l >= 0) {
				res += t[l];
		} else if (r < t.size() && l < 0) {
				res += t[r];
		}	
		r++;
		l--;
	}
	res += t[p];
	cout << res << endl;
	return 0;
}
