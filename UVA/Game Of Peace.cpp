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



long long int gcd(long long int a, long long int b){
    a = abs(a); b = abs(b);
    return (b==0) ? a : gcd(b, a%b);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    int k = 1;
    while (t--) {
        int x, n, m, y;
        int res = 0;
        cin >> x >> n >> y >> m;
        long long a, b;
        a = x;
        b = 0;
        lp (i, n) {
            if ( a >= b) {
                b += a;
            } else if (b > a) {
                a += b;
            }
        }
        if (m >= n){
            if ( a >= b) {
                a += y;
            } else if (b > a) {
                b += y;
            }
        }

        cout << "Case " << k++ << ": " <<gcd(a, b) << endl;
    }
    return 0;
}

