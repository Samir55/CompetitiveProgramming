#include <iostream>
#include <string>

using namespace std;
int main() {
	string s;
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		if ( s.size() <= 10) cout << s << endl;
		else {
			cout << s[0];
			cout << s.size() - 2;
			cout << s.back() << endl;
		}
	}
	return 0;
}
