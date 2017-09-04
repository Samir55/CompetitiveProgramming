#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	vector<int> p;
	cin >> n;
	int c = n;
	while (c--) {
		int x;
		cin >> x;
		p.push_back(x);
	}
	int  i =  0;
	cout << p[i+1] - p[i] <<  " " << p.back() - p[i] << endl;
	for (i = 1; i < n - 1; i++) {
		cout << min(p[i] - p[i-1], p[i+1] - p[i]) << " " << max(p[i] - p.front(), p.back() - p[i]) << endl;
	}
	cout << p[i] - p[i-1] << " " << p[i] - p.front() << endl;
	return 0;
}
