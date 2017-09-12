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
	int n = 1;
	cin >> n;
	while (1) {
		double l, w, h, can;
		int m, c;
		
		cin >> w >> l >> h >> can >> m;
		if (n == 0) break;
		c = m;
		double area_win = 0;
		while (c--) {
			double w, h;
			cin >> w >> h;
			area_win += w*h;
		} 		
		double room_area = ( l * w + 2 * w * h + 2 * h * l) * n;
		double paint_area = room_area - area_win * n;
		
		
		int res = ceil(1.0 * paint_area / can);
		cout << res << endl;
		cin >> n;
	}
	return 0;
}
