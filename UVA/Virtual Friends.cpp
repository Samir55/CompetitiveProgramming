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
#define lp(i, n)        for(int i=0;i<=(int)(n);++i)

map< pair<int, int>, bool> vis;
int n, m, s, t, p;
int res = -1;
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
        rank[x] += rank[y];
    }

    int union_sets(int x, int y) {
        x = find_set(x), y = find_set(y);
        if (x != y) {
            if (rank[x] > rank[y]) swap(x, y);
            parent[x] = y; // optimize (put the smaller into the bigger set).
            rank[y] += rank[x];
            return rank[y];
        }
        return rank[y];
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


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int f;
        map<string, int> id;
        int idx = 1;
        cin >> n;
        int c = n;
        UnionFind arr(n*2+1);

        while (c--) {
            string a, b;
            cin >> a;
            cin >> b;
            if (id.count(a) <= 0) {
                id[a] = idx++;
            }
            if (id.count(b) <= 0) {
                id[b] = idx++;
            }
            cout << arr.union_sets(id[a], id[b]) << endl;
        }
    }
    return 0;
}
