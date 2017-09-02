#include <iostream>
#include <string>
using namespace std;
int main(){
	int n, res = 1;
	cin >> n;
	string s, st;
	cin >> s;
	while (n > 1) {
		cin >> st;
		if (s != st) {
			res++;
			s = st;
		}
		n--;
	}
	cout << res << endl;
return 0;
}

