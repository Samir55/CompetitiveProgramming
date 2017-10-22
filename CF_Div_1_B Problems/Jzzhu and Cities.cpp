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
vector< vector<int> > gtype;
int parent[1000007];
struct node {
	int idx;
	long long int cost;
	int type; //The type of the route to this node; train type = 2 road type = 1 root = 0
	node(int i, long long int c, int t) : idx(i), cost(c), type(t) {}
	bool operator < (const node& x) const { // "<" maxheap;
		if (cost == x.cost) {
			return type > x.type;
		}
		return cost > x.cost;
	}
};

int dijkstra(int src, int dest) {
	int c = 0;
	priority_queue<node> q;
	q.push(node(src, 0, 0));
	while (!q.empty()) {
		node x = q.top(); 
		q.pop();
		if (vis[x.idx] != -1) continue; // No better result will be found afterwards.
		vis[x.idx] = x.cost;
		if (x.type == 2) c++;
		// Push children.
		lp(i, gcost[x.idx].size()) {
			int to = gcost[x.idx][i].first;
			int route_type = gtype[x.idx][i];
			long long int cost = gcost[x.idx][i].second;
			if (vis[to] == -1) {
			q.push(node(to, x.cost + cost, route_type));
			}
		}
	}
	return c;
}

int n, m, k;

int main() {
	memset(vis, -1, sizeof(vis));
	memset(parent, -1, sizeof(parent));
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	gcost.resize(n);
	gtype.resize(n);
	lp(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		gcost[a-1].push_back({b-1, c});
		gcost[b-1].push_back({a-1, c});
		
		gtype[b-1].push_back(1);
		gtype[a-1].push_back(1);
	}
	lp(i, k) {
		int a, b;
		cin >> a >> b;
		gcost[0].push_back({a-1, b});
		gcost[a-1].push_back({0, b});
		
		gtype[0].push_back(2);
		gtype[a-1].push_back(2);
	}
	int used_trains = dijkstra(0, n-1);
	cout << k - used_trains << endl;

	return 0;
}

