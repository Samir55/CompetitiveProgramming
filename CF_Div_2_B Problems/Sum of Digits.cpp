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
	string s;
	cin >> s;
	int sum = 0, res = 0;
	while (s.size() > 1) {
		sum = 0;
		res++;
		lp(i, s.size()) {
			sum += (s[i] - '0');
		} 
		s = to_string(sum);
	}
	cout << res << endl;
	return 0;
}
