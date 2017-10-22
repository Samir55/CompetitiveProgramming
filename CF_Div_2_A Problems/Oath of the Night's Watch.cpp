#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
map<long long int, int> m; 
int main() {
	int n;
	set<long long int> ss;
	cin >> n;
	while (n--) {
		long long int x;
		cin >> x;
		m[x]++;
		ss.insert(x);
	}
	int i = 0;
	int res = 0;
	for (auto e : ss) {
		if ( i == 0 || i == ss.size()-1) {
			i++; 
			continue;
			}
		res += m[e];
		i++;
	}
	cout << res << endl;
	return 0;
}

