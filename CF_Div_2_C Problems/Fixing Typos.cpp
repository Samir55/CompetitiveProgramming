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
#define lp(i, n)        for(int i=0;i<(int)(n);++i)

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    string s, t = "";
    int k = 0, r = 0, d = 0;
    cin >> s;
    char c = s[0];
    t += c;
    r++;
    for (int i = 1; i < s.size(); i++) {
        if (c == s[i]) r++;
        else r = 1;
        if (r <= 2) t += s[i];
        c = s[i];
    }

    string v = "";

    for (int i = 0; i < t.size(); i++) {
        if (i + 3 < t.size() && t[i] == t[i+1] && t[i+2] == t[i+3]) {
            v += t[i];
            v += t[i+1];
            v += t[i+2];
            i += 3;
        }
        else v += t[i];
    }

//    cout << t << endl;
    cout << v << endl;
    return 0;
}
