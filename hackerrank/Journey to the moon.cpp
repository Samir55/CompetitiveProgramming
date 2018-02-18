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
    vector<int> rank, parent; // Use rank compression method.
    int forests;

    UnionFind(int n) {
        rank = vector<int>(n), parent = vector<int>(n);
        lp(i, n) {
            parent[i] = i;
            rank[i] = 1;
        }
        forests = n;
    }

    int find_set(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find_set(parent[x]);
    }

    void link(int x, int y) {
        if (rank[x] > rank[y]) swap(x, y);
        parent[x] = y; // The bigger into the smaller.
        rank[y] += rank[x];
    }

    bool union_sets(int x, int y) {
        x = find_set(x), y = find_set(y);
        if (x != y) {
            link(x, y);
            forests--;
        }
        return x != y;
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    UnionFind f(n);
    int a, b;
    while (cin >> a >> b) {
        f.union_sets(a, b);
    }
    long long res = 0;
    vector<int> ranks;
    set<int> parents;

    int current_size = 0;
    lp(i, n) {
        parents.insert(f.find_set(i));
        if (current_size != parents.size()) {
//            cout << f.rank[f.find_set(i)] << endl;
            ranks.push_back(f.rank[f.find_set(i)]);
            current_size = parents.size();
        }
    }
    long long sum = ranks.back();
    for (int i = current_size-2; i >=0 ; i--) {
//        cout << ranks[i] << " " << sum << endl;
        res += (ranks[i] * sum);
        sum += ranks[i];
    }
    cout << res << endl;
    return 0;
}