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
char g[10][10];
bool vis[10][10];
bool res[10][10];
int x1,y, x2, y2;
int c = 0;
int m, n;
vector<string> p;
string path = "IEHOVA";

bool dfs(int i, int j, int li) {
	// Start DFS from (x1, y1) point.
	if (i == m || j == n || i < 0 || j < 0) return false; // You have not found it.
	if (vis[i][j]) return false;
	
	vis[i][j] = true;
	c++;
	//~ cout << g[i][j] << endl;
	if (li == path.size() &&  g[i][j] != '#') {
		res[i][j] = false;
		return false;
		}
		
	if (li == path.size() &&  g[i][j] == '#') { 
		res[i][j] = true;
		return true;
	}
	
	if (g[i][j] != path[li] && g[i][j] != '@') {
		res[i][j] = false;
		return false;
	}
	
	if ( g[i][j] != '@')
		li++;
	bool rf, rl, rr;
	rf = rr = rl = false;
	
	rf = dfs (i-1, j, li);
	rr = dfs (i, j+1, li);
	rl = dfs(i, j-1, li);
	if (rf) p.push_back("forth");
	if (rl) p.push_back("left");
	if (rr) p.push_back("right");
	res[i][j] = rf | rr | rl;
	
	return res[i][j];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		c = 0;
		p = vector<string>();
		cin >> m >> n;
		lp(i, m) {
			lp(j,n) {
				vis[i][j] = 0;
				cin >> g[i][j];
				if (g[i][j] == '@') {
					x1 = i; 
					y = j;
				} else if (g[i][j] == '#') {
					x2 = i;
					y2 = j;
				}
			}
		}
		dfs(x1, y, 0);
		reverse(p.begin(), p.end());
		lp (i, p.size() -1)
			cout << p[i] << " ";
		cout << p.back();
		cout << endl;
	}
	return 0;
}
