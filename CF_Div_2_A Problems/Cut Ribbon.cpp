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

int a[3], n, dp[4004] = {};

int solve(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int ret = -9999999999;
    lp(i, 3) {
        if (n >= a[i])
            ret = max(ret, 1 + solve(n - a[i]));
    }
    return dp[n] = ret;
}


int main() {
//     freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    cin >> n >> a[0] >> a[1] >> a[2];
    cout << solve(n);
    return 0;
}