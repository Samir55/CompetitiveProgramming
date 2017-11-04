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
#define lp(i, n)        for(int i=0;i<(int)(n);++i)


struct UnionFind {
    vector<int> rank, parent, mapping; // Use rank compression method.
    vector<int> sm;

    UnionFind(int n) {
        rank = vector<int>(n), parent = vector<int>(n),  mapping = vector<int>(n),   sm = vector<int>(n);
        lp(i, n) {
            parent[i] = i;
            mapping[i] = i;
            sm[i] = i;
            rank[i] = 1;
        }
    }
    int find_set(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find_set(parent[x]);
    }

    int union_sets(int x, int y) {
        x = find_set(x), y = find_set(y);
        if (x != y) {
            if (rank[x] > rank[y]) swap(x, y);
            parent[x] = y; // optimize (put the smaller into the bigger set).
            rank[y] += rank[x];
            sm[y] += sm[x];
            return rank[y];
        }
        return rank[y];
    }

};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int c, q;
    while (cin >> c >> q) {
        map<string, int> id;
        int idx = 1;

        UnionFind arr(200005);
        int offset = c + 1;
        lp(i, q) {
            int t, a, b;
            cin >> t >> a;
            if (t == 1) {
                cin >> b;
                arr.union_sets(arr.mapping[a], arr.mapping[b]);
            } else if (t == 2){
                cin >> b;
                int pa = arr.find_set(arr.mapping[a]);
                int pb = arr.find_set(arr.mapping[b]);
                if (pa != pb) {
                    arr.rank[pa]--;
                    arr.sm[pa] -= a;

                    arr.parent[offset] = offset; // The number inside it  doesn't matter as long as we calculate using rank and sm arrays.
                    arr.rank[offset] = 1;
                    arr.sm[offset] = a;

                    arr.mapping[a] = offset;
                    offset++;

                    pa = arr.find_set(arr.mapping[a]);

                    arr.union_sets(pa, pb);
                }
            } else if (t == 3) {

                cout << arr.rank[arr.find_set(arr.mapping[a])] << " " << arr.sm[arr.find_set(arr.mapping[a])] << endl;
            }
        }
    }
    return 0;
}
