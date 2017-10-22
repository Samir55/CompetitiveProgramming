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
set<char> found_col;
char g[110][110], c;
vector<pair<int,int>> pos; 
int n, m;
int find_sur(int x, int y){
	int res = 0;	
	if (y-1 >= 0 && g[x][y-1] != '.' && found_col.find(g[x][y-1]) == found_col.end()) {
		//~ cout << x<< " " << y << endl;
		//~ cout << g[x][y-1] << endl;
		res++;
		found_col.insert(g[x][y-1]);
	} else if (y+1 <= m-1 && g[x][y+1] != '.' && found_col.find(g[x][y+1]) == found_col.end()) {
		
		//~ cout << x<< " " << y << endl;
		res++;
		//~ cout << g[x][y+1] << endl;
		found_col.insert(g[x][y+1]);
	} if ( x+1 <= n-1 && g[x+1][y] != '.' && found_col.find(g[x+1][y]) == found_col.end()) {
		//~ cout << x<< " " << y << endl;
		res++;
		//~ cout << g[x+1][y] << endl;
		found_col.insert(g[x+1][y]);
	} if ( x-1 >= 0 && g[x-1][y] != '.' && found_col.find(g[x-1][y]) == found_col.end()) {
		res++;
		//~ cout << x<< " " << y << endl;
		//~ cout << g[x-1][y] << endl;
		found_col.insert(g[x-1][y]);
	}  
	//~ cout << "the size if the found cols " << found_col.size() << endl;
	//~ cout << res << endl;
	return res;
}
int main() {
	cin >> n >> m >> c;
	lp(i, n) {
		lp(j, m) {
			cin >> g[i][j];
			if (g[i][j] == c) {
				pos.push_back(make_pair(i, j));
				found_col.insert(g[i][j]);
			}
		}
	}
	int res = 0;
	lp(i, pos.size()){
		res += find_sur(pos[i].first, pos[i].second);
	}
	cout << res << endl;
	return 0;
}
