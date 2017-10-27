#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lp2(i, n)        for(int i=1;i<(int)(n);++i)

bool vis[100067];
long long int arr[100067];
vector< vector<pair<int, long long int>> > g;
int n, c;

void dfs(int i, long long int prevsum) {
    if (vis[i]) return;
    vis[i] = 1;
    c++;
//    cout << i <<  " " <<  prevsum << endl;
    lp(j, g[i].size()) {

        if (!vis[g[i][j].first] && max(prevsum + g[i][j].second, g[i][j].second)  <= arr[g[i][j].first]) {
            dfs(g[i][j].first,  max(prevsum + g[i][j].second, g[i][j].second));
        }
    }
}
int main() {
    memset(vis, 0, sizeof(vis));
    cin >> n;
    lp2(i, n+1) {
        cin >> arr[i];
    }
    g.resize(n+1);
    lp2(i, n){
        int a, b;
        cin >> a >> b;
        g[i+1].push_back({a, b});
        g[a].push_back({i+1, b});
    }
    dfs(1, 0);
    int res =0;
    lp2(i, n+1){
        if(vis[i]) res++;
    }
//    lp2(i, n) {
//        cout << i << " " << g[i].size() <<  " ";
//        lp(j, g[i].size()) {
//     cout << g[i][j].first << " ";
//     }
//     cout << endl;
//     }

    cout << n - res << endl;
    return 0;
}
