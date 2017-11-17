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
int main() {
//    freopen("input.txt", "r", stdin);
    long long int n;
    vector<long long int> c;
    long long int rem = 0;
    bool res = false;
    cin >> n;
    long long int k = n;
    while (k--) {
        long long int a ;
        cin >> a;
        rem += a;
    }
    k = n;
    while (k--) {
        long long int b;
        cin >>  b;
        c.push_back(b);
    }
    sort (c.begin(), c.end());
    if (rem <= (c[c.size()-2] + c.back())) {
        cout << "YES" << endl;
    } else
        cout << "NO" << endl;
    return 0;
}
