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
#define vi vector<long long int>
#define pb(x) push_back(x);
int main() {
	int n, x;
	cin >> n >> x;
	vi s;
	lp(i, n) {
		int f;
		cin >> f;
		s.pb(f);
	}
	sort(s.begin(), s.end());
	long long int res = 0;
	lp(i, n) {
		res += (x * s[i]);
		x--;
		if (x <= 0 ) x = 1;
	}
	cout << res << endl;
	return 0;
}
