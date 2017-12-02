#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n;
    while (cin >> n) {
        int k;
        vector<int> t;
        cin >> k;
        for(int i=0;i < (k);++i) {
            int x;
            cin >> x;
            t.push_back(x);
        }
        int res = 0;
        int total_min = 0;
        int numt = 0;
        for (int i = (1 << k) - 1; i >= 0; i--) {
            int curr = 0;
            int nt = 0;
            for (int j = 0; j < k; j++) {
                bool bit = i & ( 1<< j);
                if (bit) {
                    curr += t[j];
                    nt++;
                }
            }
            if (curr <= n && curr >= total_min) {
                total_min = curr;
                res = i;
                numt = nt;
            }
        }
        for (int j = 0; j < k; j++) {
            bool bit = res & ( 1<< j);
            if (bit) cout << t[j] << " ";
        }
        cout << "sum:" << total_min << endl;
    }
	return 0;
}
