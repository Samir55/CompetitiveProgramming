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
	const double pi = 3.14159265358979323846;
	double r;
	cin >> r;
	double carea =  pi * r * r;
	double rarea = (2 * r * 2 * r)/2.0;
	printf("%6f\n", carea);
	printf("%6f\n", rarea);
	return 0;
}
