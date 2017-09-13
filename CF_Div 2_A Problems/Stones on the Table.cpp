# include <iostream>
# include <string>
using namespace std;
int main() {
	int n, res = 0;
	cin >> n;
	string s;
	cin >> s;
	char c = s[0];
	for (int i = 1; i < s.size(); i++){
		if ( s[i] == c) res += 1;
		else c = s[i];
	}
	cout << res << endl;
	return 0;
}
