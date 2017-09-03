#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, m;
	vector<int> b;
	cin >> n;
	int x = n, i = 0;
	b.push_back(0);
	while (n--) {
		int c;
		cin >> c;
		b.push_back(c);
	}
	n = x;
	cin >> m;
	while (m--) {
		int w,p;
		cin >> w >> p;
		b[w-1] += (p - 1);
		b[w] -= (p);
		b[w+1] += b[w];
		b[w] = 0;
	}
	x = n; i = 1;
	while (n--) {
		cout << b[i++] << endl;
	}
	return 0;
}
