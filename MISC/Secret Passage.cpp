#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)

int n, m, k;
char g[507][507];
bool vis[507][507]= {};

bool valid(int i, int j) {
	return (i >=0 && i < n && j >= 0 && j < m && g[i][j] != 'x' && !vis[i][j]);
}


long long int solve(int i, int j) {
	if (!valid(i, j)) {
		return 1e6;
	}
	if ( i == n-1 && j == m-1) {
		return 0;
	}
	vis[i][j] = 1;
	long long int u = solve(i-1, j);
	long long int d = solve(i+1, j);
	long long int l = solve(i, j+1);
	long long int r = solve(i, j-1);
	return 1 + min(min(u,d), min(l, r));
}

int main () { 
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	lp(i, n) {
		lp(j, m) {
			cin >> g[i][j];
			vis[i][j] = 0;
		}
	}
	long long int  mres = solve(0,0);
	
	
	lp(i, n) {
		lp(j, m) {
			vis[i][j] = 0;
		}
	}
	while (k--) {
		int x, y;
		cin >> x >> y;
		g[x][y] = '.';
	}

	long long int  hres = solve(0,0);
	cout  << (hres) << " " << mres << " " << (hres < mres - 5 ? "YES" : "NO") << endl;
	return 0;
}
