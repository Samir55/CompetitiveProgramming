#include <iostream>
#include <stdio.h>
using namespace std;
int a[4], res = 0;
int main() {
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
		if( s[i] == '1') res += a[0];
		else if( s[i] == '2') res += a[1];
		else if( s[i] == '3') res += a[2];
		else if( s[i] == '4') res += a[3];
	}
	cout << res << endl;
	return 0;
}
