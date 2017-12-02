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

struct stsol {
    int id;
    string s;
    stsol() {
        s = "";
    }
};

bool comp(sol a, sol b) {
    if (a.q.size() == b.q.size())
        return a.q > b.q;
    return a.q > b.q;
}

bool comp3(sol a, sol b) {
    if (a.q.size() == b.q.size())
        return a.q.front() > b.q.front();
    if (a.q.front() == b.q.front())
        return a.q.size() < b.q.size();
    return a.q.front() > b.q.front();
}
bool comp2(string a, string b) {
    return a > b;
}

void print_vec(vector<int> &b) {
    lp(i, b.size()) {
        if (i) cout << "+";
        cout << b[i];
    }
    cout << endl;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n, t;
    cin >> t >> n;
    while (n !=0) {
        vector<sol> ans;
        vector<string> ans2;
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
            stsol z;
            for (int j = 0; j < n; j++) {
                bool bit = bool(i & (1<<j));
                if (bit == 1) {
                    y.q.push_back(num[j]);
                    if (z.s.size() == 0) z.s += to_string(num[j]);
                    else {
                        z.s += "+";
                        z.s += to_string(num[j]);
                    }
                    s += num[j];
                }
            }
            if (s == t) {
                ans.push_back(y);
                ans2.push_back(z.s);
                res++;
            }
        }
        sort(ans.begin(), ans.end(), comp);
//        sort(ans2.begin(), ans2.end(), comp2);
        cout << "Sums of "<< t << ":" << endl;
        if (ans.size() == 0) {
            cout << "NONE" << endl;
        } else {
//            cout << ans2.front() << endl;
            print_vec(ans[0].q);
            printed_sol.insert(ans[0].q);
            for (int i = 1; i < ans2.size(); i++){
                if (ans[i].q != ans[i-1].q) {
                    if (printed_sol.find(ans[i].q) == printed_sol.end())
                        print_vec(ans[i].q);
                }
//                if (ans2[i] != ans2[i-1]) {
//                    cout << ans2[i] << endl;
//                }
            }
        }
        cin >> t >> n;
    }

    return 0;
}

