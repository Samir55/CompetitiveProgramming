// WIP
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

struct sol {
    vector<int> q;
};

bool comp(sol a, sol b) {
    if (a.q.size() == b.q.size())
        return a.q.front() > b.q.front();
    if (a.q.front() == b.q.front())
        return a.q.size() < b.q.size();
    return a.q.front() > b.q.front();
}

void print_vec(vector<int> &b) {
    lp(i, b.size()) {
        if (i) cout << "+";
        cout << b[i];
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t;
    cin >> t >> n;
    while (n !=0) {
        vector<sol> ans;
        vector<int> num;
        set<vector<int>> printed_sol;
        lp(i, n) {
            int x;
            cin >> x;
            num.push_back(x);
        }
        int res = 0;
        for (int i = 0; i <= (1 << n) -1; i++) {
            int s = 0;
            sol y;
            for (int j = 0; j < n; j++) {
               bool bit = bool(i & (1<<j));
                if (bit == 1) {
                   y.q.push_back(num[j]);
                    s += num[j];
                }
            }
            if (s == t) {
                ans.push_back(y);
                res++;
            }
        }
        sort(ans.begin(), ans.end(), comp);
        cout << "Sums of "<< t << ":" << endl;
        if (ans.size() == 0) {
            cout << "NONE" << endl;
        } else {
            print_vec(ans[0].q);
            printed_sol.insert(ans[0].q);
            for (int i = 1; i < ans.size(); i++){
                if (ans[i].q != ans[i-1].q) {
                    if (printed_sol.find(ans[i].q) == printed_sol.end())
                        print_vec(ans[i].q);
                }
            }
        }
        cin >> t >> n;
    }

    return 0;
}

