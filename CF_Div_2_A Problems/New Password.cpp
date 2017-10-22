#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int main() {
	string s = "abcdefghijklmnopqrstuvwxyz", res, cur;
	int n , k;
	int j = 0;
	int p = 0;
	cin >> n >> k;
	while (k--) {
		cur += s[j++];
	}
	res = cur;
	for (int i = cur.size(); i < n; i++) {
		res += cur[p];
		p = (p+1)%cur.size(); 
	}
	cout << res << endl;
	return 0;
}
