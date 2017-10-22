#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)

long long int vis[1000096];
vector< vector<pair<int, int>>> gcost;
int parent[1000007];
struct node {
	int idx;
	long long int cost;
	int parent;
	node(int i, long long int c, int p) : idx(i), cost(c), parent(p) {}
	bool operator < (const node& x) const { // "<" maxheap;
		return cost > x.cost;
	}
};

int dijkstra(int src, int dest) {
	priority_queue<node> q;
	q.push(node(src, 0, -1));
	while (!q.empty()) {
		node x = q.top(); 
		q.pop();
		if (vis[x.idx] != -1) continue; // No better result will be found afterwards.
		vis[x.idx] = x.cost;
		parent[x.idx] = x.parent;
		if(x.idx == dest) return x.idx;
		// Push children.
		lp(i, gcost[x.idx].size()) {
			int to = gcost[x.idx][i].first;
			long long int cost = gcost[x.idx][i].second;
			if (vis[to] == -1) {
			q.push(node(to, x.cost + cost, x.idx));
			}
		}
	}
	return -1;
}

int n, m;

int main() {
	memset(vis, -1, sizeof(vis));
	memset(parent, -1, sizeof(parent));
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	gcost.resize(n);
	lp(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		gcost[a-1].push_back({b-1, c});
		gcost[b-1].push_back({a-1, c});
	}
	int last_node = dijkstra(0, n-1);
	if (last_node == -1) { cout << -1 << endl;  return 0; }
	vector<int> path;
	path.push_back(last_node+1); 
	while( parent[last_node] != -1) {
		path.push_back(parent[last_node]+1);
		last_node = parent[last_node];
	}
	reverse(path.begin(), path.end());
	lp(i, path.size()) {
		cout << path[i] << " ";
	}
	cout << endl;
	return 0;
}

