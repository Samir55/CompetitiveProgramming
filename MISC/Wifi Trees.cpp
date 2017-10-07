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
int main () { 
	int t;
	//~ freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		long long int d, h, s;
		cin >> d >> h >> s;
		long long int ans =  d/2;
		ans = min(ans, h);
		long long int res = ans * (d-ans) *s;
		cout << ans << " " << res << endl;
	}
	return 0;
}


