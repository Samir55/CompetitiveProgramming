#include <iostream>
using namespace std;
int main() {
	int n, b, d;
	int res = 0;
	int s = 0;
	cin >> n >> b >> d;
	for (int i = 0 ; i < n; i++) {
		int x;
		cin >> x;
		if (x <= b) s += x;
		if (s > d) {
			res++;
			s = 0;
		} 
	}
	cout << res << endl;
	return 0;
}
