#include <iostream>
using namespace std;
int main() {
	int n, d = 0;
	long long int x, aval= 0;
	cin >> n >> x;
	aval = x;
	while (n--) {
		char c;
		cin >> c;
		long long int p;
		cin >> p;
		if (c == '+') aval += p;
		else {
			if (p <= aval) aval -= p;
			else d++;
		}
	}
	cout << aval << " " << d << endl;
	return 0;
}
