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

map<int, long long int> dp;

long long int solve(long long int n) {
    if (n == 0) return 0;
    if(dp[n] != 0) return dp[n];
    long long int t = solve(n/2) + solve(n/3) + solve(n/4);
    if (t > n) dp[n] = t;
    else dp[n] = n;
    return dp[n];

}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//int res[1000000009]; // Use tabulation if it was small in size.
//    memset(res, 0, sizeof(res));
    long long int n;
//
//    res[0] = 0;
//    res[1] = 1;
//    res[2] = 2;
//    res[3] = 3;
//    res[4] = 5;
//    res[5] = 4;
//    for(long long int i = 6; i <= n; i++) {
//        res[i] = res[i/2] + res[i/3] + res[i/5];
//    }
//    cout << res[n] << endl;
    while(scanf("%ld", &n) != EOF)
        cout << solve(n) << endl;
    return 0;
}
