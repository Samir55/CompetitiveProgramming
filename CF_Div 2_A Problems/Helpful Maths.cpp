#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	string o;
	vector<int> n;
	cin >> o;
	for (int i = 0; i < o.size(); i++) {
		if (o[i] == '1') n.push_back(1);
		else if (o[i] == '2') n.push_back(2);
		else if (o[i] == '3') n.push_back(3);
	}
	sort (n.begin(), n.end());
	for (int i = 0; i < n.size() - 1; i++) {
		cout << n[i] << '+';
	}
	cout << n.back() << endl;
	return 0;
}
