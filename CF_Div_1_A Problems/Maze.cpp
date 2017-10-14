#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
int n, m, k;
char g[505][505];
bool vis[505][505];
int gf = 0;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

vector<pair<int, int>> path;

bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && g[i][j] != '#';
}

void bfs(int srci, int srcj) {
	int f = 1;
	vis[srci][srcj] = true;
	queue<pair<int, int>>q;
	q.push({srci, srcj});
	//~ cout << srci << " " << srcj << endl;
	while (!q.empty()) {
		pair<int, int> u = q.front(); q.pop();
		int i = u.first; int j = u.second;
		if (k > 0 && f-k > 0 && g[i][j] == '.') g[i][j] = 'X', k--; 
		else if (g[i][j] == '.') f++;
		lp(c, 4) {
			int nr = i+ dr[c];
			int nc = j+ dc[c];
			if (valid(nr, nc)) {
				//~ cout << nr << " " << nc << endl;
				q.push({nr, nc}), vis[nr][nc] = true;
			} 
		}		
	}
}

void dfs(int i, int j) {
	if(!valid(i, j)) return;
	vis[i][j] = true;
	path.push_back({i, j});
	lp(c, 4) {
			int nr = i+ dr[c];
			int nc = j+ dc[c];
			if (valid(nr, nc)) {
				dfs(nr, nc);
			} 
	}
}

int main() { 
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	lp(i, n) {
		lp(j, m) {
			cin >> g[i][j];
		}
	}
	//~ lp(i, n) {
		//~ lp(j, m) {
			//~ cout << g[i][j];
		//~ }
		//~ cout << endl;
	//~ }
	lp(i, n) {
		lp(j, m) {
			if (k > 0 && g[i][j] == '.'){
				 dfs(i, j);
				 reverse(path.begin(), path.end()); // Howa Hay5osh marra wa7da.
				 lp(ii, path.size()) {
					 if (k <=0) break;
					 g[path[ii].first][path[ii].second] = 'X';
					 k--;
				 }
			 }
		}
	}
	lp(i, n) {
		lp(j, m) {
			cout << g[i][j];
		}
		cout << endl;
	}
	return 0;
}
