#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
set<int> nums;
vector<string> ns;
string s;
int n;
vector<int> digs;
int main() {
    cin >> s;
    int x = stoi(s);
    lp(i, s.size()) {
        digs.push_back(s[i] - '0');
    }
    for (int i1 = 0; i1 < digs.size(); i1++) {
        int p = 0;
        if(digs.size() == 1){
            cout << 0 << endl;
            return 0;
        }
        for (int i2 = 0; (digs.size() > 1) && i2 < digs.size(); i2++) {
            if (i1 == i2 ) continue;
            if(digs.size() == 2){
                p = 0;
                p = digs[i1] * 10;
                p+= digs[i2];
                nums.insert(p);
            }
            for (int i3 = 0; (digs.size() > 2) && i3 < digs.size(); i3++) {
                if (i3 == i1 || i3 == i2) continue;
                if(digs.size() == 3){
                    p = 0;
                    p += digs[i1] * 100;
                    p += digs[i2] * 10;
                    p += digs[i3];
                    nums.insert(p);
                }
                for (int i4 = 0; (digs.size() > 3) && i4 < digs.size(); i4++) {
                    if (i4 == i1 || i4 == i2 || i4 == i3) continue;
                    if(digs.size() == 4){
                        p = 0;
                        p += digs[i1] * 1000;
                        p += digs[i2] * 100;
                        p += digs[i3] * 10;
                        p += digs[i4];
                        nums.insert(p);
                    }
                    for (int i5 = 0; (digs.size()) > 4 && i5 < digs.size(); i5++) {
                        if (i5 == i1 || i5 == i2 || i5 == i3 || i5 == i4) continue;
                        p += s[i5];
                        if(digs.size() == 5){
                            p = 0;
                            p += digs[i1] * 10000;
                            p += digs[i2] * 1000;
                            p += digs[i3] * 100;
                            p += digs[i4] * 10;
                            p += digs[i5];
                            nums.insert(p);
                        }
                        for (int i6 = 0; (digs.size()) > 5 && i6 < digs.size(); i6++) {
							if (i6 == i1 || i6 == i2 || i6 == i3 || i6 == i4 || i6 == i5) continue;
							p += s[i6];
							if(digs.size() == 6){
                            p = 0;
                            p += digs[i1] * 100000;
                            p += digs[i2] * 10000;
                            p += digs[i3] * 1000;
                            p += digs[i4] * 100;
                            p += digs[i5] * 10;
                            p += digs[i6];
                            nums.insert(p);
                        }
						}
                    }
                }
            }
        }
    }
    
    for (auto nu : nums){
        if (nu > x) {
            cout << nu << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}

