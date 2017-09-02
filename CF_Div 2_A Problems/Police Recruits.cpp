#include <iostream>
using namespace std;
int main() {
	int n, res = 0, p = 0;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if ( x != -1) p += x;
		else {
			if (p > 0) p--;
			else res++;
		}
	}
	cout << res << endl;
	return 0;

}
