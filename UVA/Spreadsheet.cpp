//WIP
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

struct form{
    int x;
    int y;
    bool c;
    vector<pair<int, int>> terms;
};

int m, n;
form fs[1001][18999];
vector<form> fa;
bool is_c[1001][18999];
int res[1001][18999];

pair<int, int> get_row_col(string s) {
    string r, c;
    for (auto ch : s) {
        if(ch >= 'A' && ch <= 'Z') c += ch;
        else r += ch;
    }
    int rc = 0, powe = 0;
    for (int i = int(c.size())-1; i >= 0; i--) {
        rc += pow(26, powe) * (c[i] - 'A');
        powe++;
    }
    return make_pair(stoi(r)-1, rc);
}

int dfs(int i, int j) {
    if (is_c[i][j]) return res[i][j];
    is_c[i][j] = true;

    int &ret = res[i][j];
    for (auto t : fs[i][j].terms) {
        if (is_c[t.first][t.second]) ret += res[t.first][t.second];
        else ret += dfs(t.first, t.second);
    }
    return ret;
}

void calc () {
    for (auto f : fa) {
        if (!is_c[f.x][f.y]) {
            res[f.x][f.y] = dfs(f.x, f.y);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;

    while (t--) {
        memset(is_c, 0, sizeof(is_c));
        memset(res, 0, sizeof(res));
        fa = vector<form>();

        cin >> m >> n;
        lp (i, n) {
            lp(j, m) {
                fs[i][j] = form();
                string p;
                cin >> p;
                if  (p.front() == '=') {
                    form nf;
                    nf.x = i;
                    nf.y = j;
                    string vt = "";
                    for (int k = 1; k <p.size(); k++) {
                        if (p[k] != '+')  vt += p[k];
                        else {
                            pair<int, int> d = get_row_col(vt);
                            nf.terms.push_back(d);
                            vt = "";
                        }
                    }
                    if (!vt.empty()) {
                        pair<int, int> d = get_row_col(vt);
                        nf.terms.push_back(d);
                    }
                    fs[i][j] = nf;
                    fa.push_back(nf);
                } else {
                    is_c[i][j] = true;
                    res[i][j] = stoi(p);
                }
            }
        }

        calc();

        lp(i, n) {
            lp(j, m) {
                if (j) cout << " ";
                cout << res[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
