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
	int n, res = 0;
	vector<int> h;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		h.push_back(x);
	}
	for (int i = 0; i < int(h.size()); i++) {
		int c = 1, lr = h[i], ll = h[i]; 
		for (int j = i+1; j < int(h.size()); j++) {
			if (h[j] <= lr) c++;
			else break;
			lr = h[j];
		} 
		for (int k = i -1; k >= 0; k--) {
			if (h[k] <= ll) c++;
			else break;
			ll = h[k];
		} 
		res = max(c, res);
	}
	cout << res << endl;
	return 0;
}
