#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
int n, m, x, y;
char g[55][55];
bool vis[55][55];
bool found = false;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j];
}

void dfs(int i, int j, int count, char col) {
	if (!valid(i, j) || g[i][j] != col) { return;} 
	//~ cout << i << " " << j << " " << col << " " << count << endl;
	vis[i][j] = true;
	count++;
	lp(c, 4) {
		int ni = i + dr[c];
		int nj = j + dc[c];
		if ( ni ==  x && nj == y && vis[ni][nj] && col == g[ni][nj] && count >= 4)  {
			found  = true;
			//~ cout << col << " " << ni << " " << nj << " " << i << " " << j << " " << count << endl;
		}
		if (!vis[ni][nj]) {
			dfs(ni, nj, count, col);
		}
	}
}

bool dfs(int i, int j, int k, int cd) {
	return false;
}

int main() { 
 	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	lp(i, n) {
		lp(j, m) {
			cin >> g[i][j];
		}
	}

	lp(i, n) {
		lp(j, m) {
			x = i;
			y = j;
			found = false;
			memset(vis, 0, sizeof(vis));
			dfs(i, j, 0, g[i][j]);
			if (found) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
