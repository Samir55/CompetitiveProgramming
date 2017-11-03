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

bool vis[50006];
vector<vector<int>> g;

void dfs(int i, int n) {
    if (i > n) {
        return;
    }
    vis[i] = true;
    lp(j, g[i].size()) {
        if (!vis[g[i][j]]) {
            dfs(g[i][j], n);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int t = 0;
    while ( n != 0 && m != 0) {

        g = vector<vector<int>>();
        g.resize(n+1);

        memset(vis, 0, sizeof(vis));

        t++;
        lp (i, m) {
            int a , b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int connected_components = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                connected_components++;
                dfs(i, n);
            }
        }
        cout << "Case "<< t << ": " << connected_components << endl;
        cin >> n >> m;
    }
    return 0;
}
