#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)

int dp[100008][2];
int k, n, d;

int calc(int sum, bool found) {
	if (sum > n || (sum == n && !found)) return 0;
    if (sum == n && found) return 1;
    int &ret = dp[sum][found];
    if (ret != -1) return ret;
    ret = 0;
    lp(i, k) {
        ret += calc(sum + (i+1), found || (i+1) >= d);
    }
    return ret;
}

int main() {
//	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof dp);
	cin >> n >> k >> d;
	cout << calc(0, false);
	return 0;
}
