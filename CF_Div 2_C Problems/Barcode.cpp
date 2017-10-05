#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define clr(v, d)		memset(v, d, sizeof(v))
int n, m, x, y;
int dots[10020];
int dp[1000+9][2];
char g[1000+9][1000+9];
int res[1000+9][2][1000+9];
bool vis[1000+9][2][1000+9];

map<pair<int, int>, int> l;

int const d = 0;
int const w  = 1;
//~ 
//~ int solve_tabulation() {
	//~ dp[0][d] = n - dots[0];
	//~ dp[0][w] = dots[0];
	//~ for (int i = 1;i < m; i++) {
		//~ bool fw = 0, fd = 0;
		//~ // try to chenge the current columns into white.
		//~ if (l[{i-1, w}] < y || l[{i-1, w}] < x ) dp[i][w] = dp[i-1][w] + dots[i], fw = 1;
		//~ if (l[{i-1, d}] >= x) dp[i][w] = min(dp[i][w], dp[i-1][d] + dots[i]), l[{i, w}] = 1, l[{i, d}] = 0; 
		//~ 
		//~ if (l[{i-1, d}] < y || l[{i-1, d}] < x ) dp[i][d] = dp[i-1][d] + n - dots[i], fd = 1;
		//~ if (l[{i-1, w}] >= x) dp[i][d] = min(dp[i][d], dp[i-1][w] + n - dots[i]), l[{i, d}] = 1, l[{i, w}] = 0;
		//~ 
		//~ if(fd) l[{i, d}] = l[{i-1, d}] + 1;
		//~ if(fw) l[{i, w}] = l[{i-1, w}] + 1;
		//~ cout << dots[i] << " " <<  dp[i][w] << " " << dp[i][d] << endl;
	//~ }  	
	//~ return min(dp[n-1][w], dp[n-1][d]);
//~ }
//~ 
//~ int solve() {
	//~ dp[0][d] = n - dots[0];
	//~ dp[0][w] = dots[0];
	//~ for (int i = 1;i < m; i++) {
		//~ bool fw = 0, fd = 0;
		//~ // try to chenge the current columns into white.
		//~ if (l[{i-1, w}] < y || l[{i-1, w}] < x ) dp[i][w] = dp[i-1][w] + dots[i], fw = 1;
		//~ if (l[{i-1, d}] >= x) dp[i][w] = min(dp[i][w], dp[i-1][d] + dots[i]), l[{i-1, w}]++; 
		//~ 
		//~ if (l[{i-1, d}] < y || l[{i-1, d}] < x ) dp[i][d] = dp[i-1][d] + n - dots[i], fw = 1;
		//~ if (l[{i-1, w}] >= x) dp[i][d] = min(dp[i][d], dp[i-1][w] + n - dots[i]), l[{i-1, d}]++;
		//~ 
		//~ if(fd) l[{i-1, d}]++;
		//~ if(fw) l[{i-1, w}]++;
	//~ }  	
	//~ return min(dp[m-1][w], dp[m-1][d]);
//~ }

int solve(int i, int c,  int len) {
	if (i == m) {
		return (len < x || len > y) ?  1e9: 0;
	}
	
	int &ans = res[i][c][len]; 
	if (vis[i][c][len]) return ans;
	vis[i][c][len] = 1;	
	int rd, rw;
	rw = rd = 1e9;
	
	if (i == 0 || (c == w && len < y) || (c == d && len >= x)) {
		rw = n - dots[i] + solve(i+1, w, (c == w) ? len+1 : 1);
	}
	
	if (i == 0 || (c == d && len < y) || (c == w && len >= x)) {
		rd = dots[i] + solve(i+1, d, (c == d) ? len+1 : 1);
	}	
	

	ans = min(rd, rw);
	return ans;
	
}

int main() { 
	clr(res,0);
	clr(dp, 0);
	clr(vis, 0);
	//~ freopen("input.txt", "r", stdin);
	cin >> n >> m >> x >> y;
	lp(i, n) {
		lp(j, m) {
			cin >> g[i][j];
			if (g[i][j] == '.') {
				dots[j]++;
			}
		}
	}
	//~ cout << solve() << endl;
	cout << solve(0, 2, 0) << endl;
	//~ cout << solve_tabulation() << endl;
	return 0;
}
