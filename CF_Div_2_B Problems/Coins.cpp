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
	char names[] = {'A', 'B', 'C'}; 
	int res[3] = {};
	lp(i, 3) {
		char a, b, c;
		cin >> a >> b >> c;
		if ( b == '<') {
			res[(c - 'A')]++;
		} else {
			res[(a - 'A')]++;
		}
	}
	int freq[9] ={};
	lp(i, 3) {
		freq[res[i]]++;
	}
	if (freq[0] != 1 || freq[1] != 1 || freq[2] != 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	lp(i, 3) {
		if (res[i] == 0) cout << names[i];
	}
	lp(i, 3) {
		if (res[i] == 1) cout << names[i];
	}
	lp(i, 3) {
		if (res[i] == 2) cout << names[i];
	}
	cout << endl;
	return 0;
}
