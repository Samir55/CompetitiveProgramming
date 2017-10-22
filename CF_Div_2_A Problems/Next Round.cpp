#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int main() {
	int x = 0, n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s.find('+') != -1) x++;
		else x--;
	}
	cout << x << endl;
	return 0;
}
