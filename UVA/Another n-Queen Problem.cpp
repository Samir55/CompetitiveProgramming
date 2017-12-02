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

string grid[20];
int rw[20];
int n = 0;
int res = 0;
int limit = 0;

void solve_n_queen(int i, int row, int l , int r) {
    if (row >= limit) {
        res++;
        return;
    }

    int available_pos = limit & ~(row | l | r | rw[i]);
    while (available_pos != 0) {
        int new_pos = available_pos & (-available_pos); // The most right available bit.
        available_pos -= new_pos;
        solve_n_queen(i+1, new_pos+row, (new_pos+l) << 1, (new_pos+r) >> 1);
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> n;
    while (n != 0) {
        limit = (1 << n) -1;
        lp (i, n) {
            cin >> grid[i];
            rw[i] = 0;
            lp(j, n) {
                if (grid[i][j] == '*') {
                    rw[i] = rw[i] | (1<<j);
                }
            }
        }
        solve_n_queen(0, 0, 0, 0);
        cout << "Case " << t++ << ": " << res << endl;
        res = 0;
        cin >> n;
    }
    return 0;
}
