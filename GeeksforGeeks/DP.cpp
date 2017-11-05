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

int res[1000007];

int solve(int n) {
    if(n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (res[n] != 0) return res[n];
    return res[n] = solve(n-1) + solve(n-3) + solve(n-5);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(res, 0, sizeof(res));

    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
