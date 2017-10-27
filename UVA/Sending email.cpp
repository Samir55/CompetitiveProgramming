#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)

int n, m, s, t;
vector< vector<pair<int, int>>> gcost;
int vis[20010];

struct node {
    int idx;
    int cost;
    node(int i, int c) : idx(i), cost(c) {}
    bool operator < (const node& x) const { // "<" maxheap;
        return cost > x.cost;
    }
};


int Dijkstra(int src, int dest) {
    priority_queue<node> q;
    q.push(node(src, 0));
    while (!q.empty()) {
        node x = q.top();
        q.pop();
        if (vis[x.idx] != -1) continue; // No better result will be found afterwards.
        vis[x.idx] = x.cost;
        if (x.idx == dest) return x.cost;
        // Push children.
        lp(i, gcost[x.idx].size()) {
            int to = gcost[x.idx][i].first;
            int cost = gcost[x.idx][i].second;
            if (vis[to] == -1)
                q.push(node(to, x.cost + cost));
        }
    }
    return -1;
}

int main() {
    int x;
    cin >> x;
    lp(j, x) {
        gcost = vector<vector<pair<int, int>>>();
        memset(vis, -1, sizeof(vis));
        cin >> n >> m >> s >> t;
        gcost.resize(n);
        lp(i, m) {
            int a, b, c;
            cin >> a >> b >> c;
            gcost[a].push_back({b,c});
            swap(a, b);
            gcost[a].push_back({b,c});
        }
//        lp(i, n) {
//            cout << i << " " << gcost[i].size() <<  " ";
//            lp(j, gcost[i].size()) {
//               cout << gcost[i][j].second << " ";
//            }
//            cout << endl;
//        }
        int res = Dijkstra(s, t);
        cout << "Case #" << j+1 << ": ";
        cout << (res != -1 ? to_string(res): "unreachable") << endl;
    }
    return 0;
}