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
	int n, k;
	int h[1000067]; 
	cin >> n >> k;
	lp(i, n) {
		cin >> h[i];
	}
	int res = 0, s =0;
	lp(i, k) {
		s += h[i];
	}
	res = s;
	int p = 1;
	for (int i = k; i < n; i++) {
		 s = s + h[i] - h[i-k];
		 //~ cout << s<< endl;
		 if (res > s) {
			 //~ cout << s << endl;
			 		 //~ cout << i-k << endl;
			 p = i - k + 1 +1;
			 res = s;
		 }
	}
	cout << p << endl;
	return 0;
}
