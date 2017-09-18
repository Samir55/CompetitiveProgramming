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
	int maxside = 0.0;
	int n, w, h;
	cin >> n >> w >> h;
	maxside = sqrt((w * w + h * h));
	//~ cout << maxside << " the maxside \n";
	while (n--) {
		int l;
		cin >> l;
		if ( l <= maxside) 
		cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}

