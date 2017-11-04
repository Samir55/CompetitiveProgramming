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
