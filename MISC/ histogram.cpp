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
	cin >> n;
	while (n != 0) {
		vector<int> t;
		int m = 0;
		int c = n;
		while (c--) {
			int x;
			cin >> x;
			if (x > m) m = x; 
			t.push_back(x);
		}
		//~ cout << m << endl;
		for (int i = m; i >= 1; i--) {
			lp(j, t.size()) {
				if (t[j] < i ) cout << ".";
				else cout << "*";
			}
			cout << endl;
		}
	cin >> n;
	}
	return 0;
}
