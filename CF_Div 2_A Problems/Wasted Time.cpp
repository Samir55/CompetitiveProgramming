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
	int n = 0, k  =0;
	double tdis = 0;
	cin >> n >> k;
	int c = n;
	int a, b;
	cin >> a >> b;
	c--;
	while (c--) {
		int c, d;
		cin >> c >> d;
		tdis += sqrt( (a-c)*(a-c) + (b-d) * (b-d));
		a = c;
		b = d;
	}
	double res = tdis / 50 * k;
	printf("%f\n", res);
	return 0;
}
