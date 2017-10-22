# include <iostream>
using namespace std;
int main() {
	int res[2] = {0,0}, n, c[1001], r = 0, l;
	cin >> n;
	int i = 0;
	l = n - 1;
	int p = 0;
	while (n--) cin >> c[i++];
	n = l + 1;
	r = 0;
	// If n is odd then s will play 1 extra turn
	while (r <= l) {
		if (c[r] >= c[l]) {
			res[p] += c[r++];		
		} else {
			res[p] += c[l--];
		}
		p = 1 - p;
	}
	cout << res[0] << " " << res[1] << endl;
	return 0;
}
