#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)

bool vis[10];
vector< vector<int> > g;

void bfs(int src) {
	vis[src] = true;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		lp(i, g[u].size()) {
			int v = g[u][i];
			if(!vis[v]) {
				q.push(v), vis[v] = true;
			}
		}
	}
}

void dfs(int i, int n) {
	if (i == n) {
		return;
	}
	lp(j, g[i].size()) {
		if (!vis[g[i][j]]) {
			dfs(j, n);
		}
	}
}

int main() {freopen("input.txt", "r", stdin); 
return 0;
}
