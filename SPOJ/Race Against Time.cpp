
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <bitset>

using namespace std;
#define all(v)                ((v).begin()), ((v).end())
#define sz(v)                ((int)((v).size()))
#define clr(v, d)            memset(v, d, sizeof(v))
#define rep(i, v)        for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)

typedef long long ll;
const int OO = (int) 1e6;
const double EPS = (1e-7);

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

#define pb                    push_back
#define MP                    make_pair
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;

int n, q;
int arr[100100];
vector<int> bks[1000];

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int bs = max(1, int(sqrt(n)));
    for (int i = 0; i < n; ++i) {
        bks[i / bs].push_back(arr[i]);
        if (bks[i / bs].size() == bs) {
            sort(bks[i / bs].begin(), bks[i / bs].end());
        }
    }
    sort(bks[(n-1) / bs].begin(), bks[(n-1) / bs].end());

    char ch;
    int l, r, x;
    for (int i = 0; i < q; ++i) {

        cin >> ch;
        if (ch == 'C') {
            cin >> l >> r >> x;
            l--,r--;
            int ans = 0;
            if (l / bs == r / bs) {

                for (int j = l; j <= r; ++j) {
                    ans += (arr[j] <= x);
                }

            } else {

                for (int j = l / bs + 1; j <= r / bs - 1; ++j) {
                    ans += upper_bound(bks[j].begin(), bks[j].end(), x) - bks[j].begin();
                }
                for (int j = l; l / bs == j / bs; ++j) {
                    ans += (arr[j] <= x);
                }
                for (int j = r; r / bs == j / bs; --j) {
                    ans += (arr[j] <= x);
                }
            }
            cout << ans << endl;

        } else {
            cin >> l >> x;
            l--;
             *lower_bound(bks[l/bs].begin(),bks[l/bs].end(), arr[l]) = x;
            sort(bks[l / bs].begin(), bks[l / bs].end());
            arr[l]=x;

        }

    }
    return 0;
}
