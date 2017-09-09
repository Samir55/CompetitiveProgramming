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
int n = 0;
int pix[50][50];
bool vis[50][50];

void dfs(int i, int j) {
	if (i == n || j == n || i < 0 || j < 0) return;
	if (vis[i][j]) return;
	if (pix[i][j] == 0) return;
	vis[i][j] = true;
	dfs(i-1, j-1);
	dfs(i-1, j);
	dfs(i-1, j+1);
	
	dfs(i, j+1);
	dfs(i, j-1);
	
	dfs(i+1, j-1);
	dfs(i+1, j);
	dfs(i+1, j+1);
}

int solve() {
	int res = 0;
	for (int i = 0;i < n; i++) {
		for (int j = 0;j < n; j++) {
			if (pix[i][j] && !vis[i][j]) {
				res++;
				dfs(i, j);
			}
			vis[i][j] = true;
		}
	}
	return res;	
}
int main() {
	int i_prob = 1;
     //~ freopen("Bumble.in", "r", stdin);
     //~ freopen("Bumble.txt", "w", stdout);
	while(cin >> n){
		for (int i = 0;i < n; i++)
			for (int j = 0;j < n; j++){
				vis[i][j] = 0;
				char c;
				cin >> c;
				pix[i][j] = c - '0';
			}
			printf("Image number %d contains %d war eagles.\n", i_prob++, solve());
	}
	return 0;
}
