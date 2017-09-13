#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int main() {
	int n, k, m, res = 0;
	vector<int> t, left;
	cin >> n >> k >> m;
	int c = k, sum = 0;
	while (c--) {
		int x;
		cin >> x;
		sum += x;
		t.push_back(x);
		left.push_back(n);
	}
	sort (t.begin(), t.end());
	res = 0;
	int tasks = (m/sum); // Number of full tasks
	tasks = tasks > n ? n :tasks;
	for (int i = 0; i <= tasks; i++){
		int m2 = m;
		int res2 = 0;
		for (int s = 0; s < k; s++)
				left[s] = n;
		res2 += ((k * i + i));
		m2 -= (i * sum);
		for (int j = 0; j < i; j++) {
			for (int s = 0; s < k; s++)
				left[s]--;
		} 
		for (c = 0; c < k; c++){
			int f = (m2/t[c]) > n ? n : (m2/t[c]);
			f = f > left[c] ? left[c] : f;
			res2 += f;
			m2 -= (t[c]*f);
		}
		res = res2 > res ? res2 : res;	
	}
	cout << res << endl;
	return 0;
}
