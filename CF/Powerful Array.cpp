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
int bs;

struct query {
    int l;
    int r;
    int id;

    query(int a, int b, int i) : l(a), r(b), id(i) {};

    bool operator<(const query &c) const {
        if (l / bs != c.l / bs) {
            return l < c.l;
        }
        return r < c.r;
    }
};

vector<query> qs;
long long fans[200005];

int  t;
int freq[1000005];
long long  ans = 0;
int arr[200009];

void add(int x) {
        ans -= (freq[x] ) * 1ll * (freq[x]) * x;
        freq[x]++;
        ans += freq[x] * 1ll * freq[x] * x;
}

void rem(int x) {

    ans -= (freq[x] ) * 1ll * (freq[x] ) * x;
    freq[x]--;
    ans += freq[x] * 1ll * freq[x] * x;

}

int main() {
    cin >> n >> t;
    lp(i, n) {
        scanf("%d", &arr[i]);
    }
    q = t;
    bs = max(1, int(sqrt(n)));

    lp(i, q) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        qs.push_back(query(a, b, i));
    }

    sort(qs.begin(), qs.end());

    int L = 0, R = -1;
    for (int i = 0; i < q; ++i) {
        int l = qs[i].l, r = qs[i].r;
        while (L > l) {
            add(arr[--L]);
        }
        while (R < r) {
            add(arr[++R]);
        }
        while (L < l) {
            rem(arr[L++]);
        }
        while (R > r) {
            rem(arr[R--]);
        }
        fans[qs[i].id] = ans;
    }

    lp(i, q) {
        printf("%lld\n", fans[i]);
    }

    return 0;
}
