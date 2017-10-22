#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int main() {
	int n, nxt;
	set<int> sn;
	cin >> n;
	nxt = n;
	while (n--) {
		int x; 
		cin >> x;
		if (x == nxt) {
			cout << x << " ";
			nxt--;
		} else {
			sn.insert(x);
		}
		while (sn.find(nxt) != sn.end()) {
			sn.erase(sn.find(nxt));
			cout << nxt-- << " ";
		}
		cout << endl;
	}
	return 0;
}

