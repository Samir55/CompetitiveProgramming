#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int t1 = 0, t2 = d;
	int N = (n/k) + (n%k ? 1 : 0); 
	int o = N * t;
	while (N--) {
		if (t1 <= t2) t1 += t;
		else t2 += t;
	}
	if ( o <= max (t1, t2)) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}
