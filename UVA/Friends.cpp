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

bool vis[30006];
vector<vector<int>> g;
int countF  = 0;
map<pair<int, int>, int> c;

void dfs(int i, int n) {
    if (i > n) {
        return;
    }
    vis[i] = true;
    countF++;
    lp(j, g[i].size()) {
        if (!vis[g[i][j]]) {
            dfs(g[i][j], n);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    int k = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        g = vector<vector<int>>();
        g.resize(n+1);
        memset(vis, 0, sizeof(vis));
        c.clear();

        lp (i, m) {
            int a , b;
            cin >> a >> b;
            if(c.count(make_pair(min(a, b), max(a, b))) <= 0) {
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }

        int connected_components = 0;
        int numberOfFriends = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                connected_components++;
                countF = 0;
                dfs(i, n);
                numberOfFriends = max(numberOfFriends, countF);
            }
        }
        cout << numberOfFriends << endl;
    }
    return 0;
}

