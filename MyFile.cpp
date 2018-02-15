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

const int OO = 1e7;

int vis[10];
vector< vector<int> > g;
vector< vector<pair<int, int>>> gcost;

// DSU

struct UnionFind {
	vector<int> rank, parent; // Use rank compression method.
	int forests;

	UnionFind(int n) {
		rank = vector<int>(n), parent = vector<int>(n);
		lp(i, n) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find_set(int x) {
		if (x == parent[x]) return x;
		return parent[x] = find_set(parent[x]);
	}

	void link(int x, int y) {
		if (rank[x] > rank[y]) swap(x, y);
		parent[x] = y; // The bigger into the smaller.
		if (rank[x] == rank[y]) rank[y]++;
		else rank[x] += rank[y];
	}

	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			link(x, y);
			forests--;
		}
		return x != y;
	}

	vector<vector<int>> connected_componenets() {
		// It gets the number of connected components dynamically, which means at each edge insertion you can calcualte the number of connected componenets
		// It has advantage over the traditional DFS.
		vector<vector<int>> list(parent.size());
		lp(i, parent.size()) {
			list[find_set(i)].push_back(i);
		}
		return list;
	}
};

// Prim's algorithm

struct edge {
    int from, to , w;
    
    edge(int from, int to, int w) : from(from), to(to), w(w) {}
    
    bool operator < (const edge& e) const {
        return w > e.w;
    }
};

pair<int, vector<edge>> mst_prim_1(vector<edge> edgelist, vector<vector<int>> adj_mat) // O(v^2)
{ 
	int cur_node = 0, n = adj_mat.size();
	int mind, mst_cost = 0, mini;
	
	vector<int> vis (n, 0), prev(n);
	vector<int> dist (n, OO);
	vector<edge> edges;
	
	lp(k, n-1) {
		vis[cur_node] = 1, mind = OO, mini = -1;
		lp(i, n) {
			if (!vis[i]) {
				if (adj_mat[cur_node][i] < dist[i]) 
					dist[i] = adj_mat[cur_node][i], prev[i] = cur_node;
				
				if (dist[i] < mind) mind = dist[i], mini = i;
			}
		}
		if (mini == -1) break;
		edges.push_back(edge(prev[mini], mini, adj_mat[prev[mini]][mini]));
		cur_node = mini, mst_cost += dist[cur_node];
	}
	if (int (edges.size()) != n) return make_pair(-OO, vector<edge>());
	return make_pair(mst_cost, edges);
}

pair<int, vector<edge> > mst_prim_2(vector< vector<edge>> adj_list) // O(E logV)
{
	int n = adj_list.size(), mst_cost = 0;
	vector<int> vis(n, 0);
	vector<edge> edges;
	
	priority_queue<edge> q;
	q.push(edge(-1, 0, 0));
	
	lp (i, n) {
		edge e = q.top(); q.pop();
		if (vis[e.to]) continue;
		vis[e.to] = true;
		mst_cost += e.w;
		
		if (e.to) edges.push_back(e);
		
		for (auto ne : adj_list[e.to]) {
			if (!vis[ne.to]) {
				q.push(ne);
			}
		}
	}
	if (int (edges.size()) != n) return make_pair(-OO, vector<edge>());
	return make_pair(mst_cost, edges);
}
 
// Kruksal algorithm.

pair<int, vector<edge>> mst_kruskal(vector<edge> edgeList, int n) {
	UnionFind uf(n);
	vector<edge> edges;
	int mst_cost = 0;
	priority_queue<edge>q;
	for (auto e : edgeList) q.push(e);
	
	while (!q.empty()) {
		edge e = q.top(); q.pop();
		
		if (uf.union_sets(e.from, e.to)) {
			mst_cost += e.w;
			edges.push_back(e);
		}
	}
	
	if (int (edges.size()) != n) return make_pair(-OO, vector<edge>());
	return make_pair(mst_cost, edges);
}

// Sieve prime numbers generator.

void sieve() {
vector<bool> isPrime(1000000+1, true);
    vector<int> primeNum;
    int i,j;
    int count = 0 ;
    
    isPrime[1] = false;
    for(i = 2; i <= 1000000; i++){
        if(isPrime[i]){
            count++;
            primeNum.push_back(i);
            for(j = i+i; j <=1000000; j+= i)
                isPrime[j] = false;
        }
    }

}

// DFS / BFS / Dijkstra.

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

/// CHECKING.
//~ lp2(i, n) {
//~ cout << i << " " << g[i].size() <<  " ";
//~ lp(j, g[i].size()) {
//~ cout << g[i][j].first << " ";
//~ }
//~ cout << endl;
//~ }

int main() {freopen("input.txt", "r", stdin);
return 0;
}
