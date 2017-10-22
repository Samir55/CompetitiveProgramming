#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define lp(i, n)        for(int i=2;i<=(int)(n);++i)
int h[100003], p[100003];
int dp[100003][3];
int n;
#define l 0
#define r 1
#define s 2
int solve () {
	// 0 left 1 right 2 stay.
	h[n+1] = 2e9+4;
	p[n+1] = 2e9+4;
	
	lp(i, n) {
		dp[i][l] = dp[i][r] = dp[i][s] = 0;
		//~ cout << p[i] << " " << "h " << h[i] << endl;
	}
	
	dp[1][l] = 1;
	dp[1][r] = (p[1] + h[1] < p[2]) ? 1 : 0;
	dp[1][s] = 1;
	
	lp(i, n) {
		// Choose to stay.
		dp[i][s] = max(dp[i-1][s], max(dp[i-1][l], dp[i-1][r]));
		// Chhose to cut left.
		dp[i][l] = dp[i-1][l]; // it's written if I cannot cut to the left in this iteration.
		if (p[i] - h[i] > p[i-1]) dp[i][l] = max (dp[i-1][l], dp[i-1][s]) + 1; // Cut left and the previous tree stayed.
		if (p[i] - h[i] > p[i-1] + h[i-1] ) dp[i][l] = max( dp[i][l], dp[i-1][r] +1); // Cut left and the previous tree stayed.
		// Chose to cut right.
		dp[i][r] = max(dp[i-1][s], max(dp[i-1][l], dp[i-1][r]));
		if (p[i] + h[i] < p[i+1]) 
		{
			 dp[i][r] += 1; // Add 1 if I can cut in the right direction.
		}
		//~ cout << dp[i][s] << " " << dp[i][l] << " " << dp[i][r] << endl;
	}
		
	return max(dp[n][s], max(dp[n][l], dp[n][r]));
}
int main () { 
	//~ freopen("input.txt", "r", stdin);
	cin >> n;
	int c = n;
	int i = 1;
	
	while (c--) {
		cin >> p[i] >> h[i];
		i++;
	}
	cout << solve() << endl;
	return 0;
}
