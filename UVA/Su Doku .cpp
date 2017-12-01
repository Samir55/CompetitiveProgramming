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
int n;
int grid[11][11];
int ur[11][11], uc[11][11], ug[11][11];

bool found_khalas;

void solve(int el) {
    if (found_khalas)
        return;

    if (el == n * n * n * n) {
        found_khalas = true;
        // Print the solution, yasta.
        lp(i, n*n) {
            lp(j, n*n) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    int row = el /(n * n), col = el % (n * n);

    if (grid[row][col] != 0)
        solve(el+1);
    else {
        int gr = (row / n * n) + (col / n);
        for (int i = 1; i <= n * n; i++) {
            if (!ur[row][i] && !uc[col][i] && !ug[gr][i]) {
                // Set and try.
                ur[row][i] = true;
                uc[col][i] = true;
                ug[gr][i] = true;
                grid[row][col] = i;
                solve(el+1);
                // On failure, unset and loop to get the another available one.
                // If nothing is found available,
                // the recursion call would return to it's caller and if no solution at all the parent solve would return without changing found_khalas value.
                ur[row][i] = false;
                uc[col][i] = false;
                ug[gr][i] = false;
                grid[row][col] = 0;
            }
        }
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    while (cin >> n) {
        memset(grid, 0, sizeof(grid));
        memset(uc, 0, sizeof(uc));
        memset(ur, 0, sizeof(ur));
        memset(ug, 0, sizeof(ug));
        found_khalas = 0;

        for (int i = 0; i < n*n; i++) {
            for (int j = 0; j < n*n; j++) {
                cin >> grid[i][j];
                if (grid[i][j] != 0) {
                    ur[i][grid[i][j]] = true;
                    uc[j][grid[i][j]] = true;
                    ug[i / n * n + j / n][grid[i][j]] = true;
                }
            }
        }

        solve(0);

        if (!found_khalas) {
            cout << "NO SOLUTION" << endl;
        }
    }
    return 0;
}
