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

string ls = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int found = 0;
bool done = false;
int n, l;
string s;

bool solve(int len) {
    found += 1;
    if (found > n) {
        done = true;
        lp(i, s.size()) {
            bool new_line = false;
            if (i > 0 && i%(16*4) == 0) {
                new_line = true;
                cout << '\n';
            }
            if (!new_line && i > 0 && i%4 == 0) {
                cout << " ";
                new_line = false;
            }
            cout << s[i];
        }
        cout << endl;
        cout << len << endl;
        return 0 ;
    }
    string tmp = s;
    for (int x = 0; x < l ; x++) {
        s += ls[x];
        bool safe = true;
        for (int i = 1; i * 2 <= len + 1; i++) {
            bool flag = true;
            for (int k = 0; k < i; k++) {
                if (s[len-k] != s[len-k-i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                safe = false;
                break;
            }
        }
        if (safe) {
            if (!solve(len+1)) return 0;
        }
        s = tmp;
    }
    return true;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin >> n >> l;
    while (n !=0 && l != 0) {
        found = 0;
        done = false;
        s = "";
        solve(0);
        cin >> n >>  l;
    }
    return 0;
}