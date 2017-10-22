#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	string s;
	set<char> l;
	getline(cin, s);
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] != ' ' && s[i] != ',') l.insert(s[i]);
	}
	cout << l.size() << endl;
	return 0;
}
