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

int vis[10];
vector< vector<int> > g;
vector< vector<pair<int, int>>> gcost;

/// CHECKING.
//~ lp2(i, n) {
        //~ cout << i << " " << g[i].size() <<  " ";
        //~ lp(j, g[i].size()) {
           //~ cout << g[i][j].first << " ";
        //~ }
        //~ cout << endl;
    //~ }
    
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

struct node {
	int idx;
	int cost;
	node(int i, int c) : idx(i), cost(c) {}
	bool operator < (const node& x) const { // "<" maxheap;
		return cost > x.cost;
	}
};

void Dijkstra(int src, int dest = -1000) {
	priority_queue<node> q;
	q.push(node(src, 0));
	while (!q.empty()) {
		node x = q.top(); 
		q.pop();
		if (vis[x.idx] != -1) continue; // No better result will be found afterwards.
		vis[x.idx] = x.cost;
		//if(dest != -100 && x.idx == dest) return x.cost;
		// Push children.
		lp(i, gcost[x.idx].size()) {
			int to = gcost[x.idx][i].first;
			int cost = gcost[x.idx][i].second;
			if (vis[to] == -1) 
				q.push(node(to, x.cost + cost));
		}
	}
}

int main() {freopen("input.txt", "r", stdin); 
return 0;
}
