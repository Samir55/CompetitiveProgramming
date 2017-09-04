#include <iostream>
using namespace std;
int p[109];
int main() {
	int n, i = 0;
	cin >> n;
	int c = n;
	while (c--) {
		int x;
		cin >> x;
		p[x-1] = i++;
	}
	for (int i = 0; i < n; i++)
		cout << p[i] + 1 << " ";
	cout << endl;
	return 0;
}
