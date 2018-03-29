#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

int solve(string a, string b) {
	int ret = 0;
	int dp[150][150] = {};
	
	for (int i  = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				int x, y;
				x = dp[i-1][j];
				y = dp[i][j-1];
				dp[i][j] = max(x, y);
			}
		}
	}

	ret = dp[a.size()][b.size()];
	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);
	string a, b;
	int i = 1;

	while(getline(cin,a)&&a[0]!='#'){
        getline(cin,b);
			cout << "Case #" << i++ << ": you can visit at most " << solve(a, b) << " cities." << endl;
	}

	return 0;
}
