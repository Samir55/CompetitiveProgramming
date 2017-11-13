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
map<string, int> dpm;
string s;

//int solve(int i, int n){ // I don't know why it gives time limit.
//    if (i >= n) return 1;
//    string t = s.substr(0, i+1);
//    if (dpm[t] != 0)
//        return dpm[t];
//    bool a = 0;
//    if (i < n-1) {
//        if ((s[i] - '0')*10 + (s[i+1] - '0') <= 26)
//            a = true;
//    }
//    int r1 = solve(i+1, n);
//    if (a) {
//        int r2 = solve(i+2, n);
//        return dpm[t] =  r1 + r2;
//    }
//    return dpm[t] = r1;
//}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while(cin >> s) {
        if (s == "0") return 0;
        vector<int> dp(5002,0);
        dp[0] = 1;
        dp[1] = 1;
        int l = s.size();
        for (int i = 2; i <= l; ++i) {
            dp[i] = dp[i-1];
            if (s[i-2] == '1') dp[i] += dp[i-2];
            else if (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6') dp[i] += dp[i-2];
        }
        cout << dp[l] << endl;
//        dpm.clear();
    }
    return 0;
}
