#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string s[] = {"0/1", "1/6", "1/3", "1/2", "2/3", "5/6", "1/1"};
int main() {
	int y, w;
	cin >> y >> w;
	int res =  (6 - max(y,w) + 1.0);
	//~ if (fabs(res - 0) < 1e-5) cout << s[0];
	//~ else if (fabs(res - 0.1666666 ) < 1e-5) cout << s[1];
	//~ else if (fabs(res - 0.3333333) < 1e-5) cout << s[2];
	//~ else if (fabs(res - 0.5000000 ) < 1e-5) cout << s[3];
	//~ else if (fabs(res - 0.6666666) < 1e-5) cout << s[4];
	//~ else if (fabs(res - 0.8333333) < 1e-5) cout << s[5];
	//~ else if (fabs(res - 0.0000000) < 1e-5) cout << s[6];
	if ( res == 7) cout << s[0];
	else if (res == 1) cout << s[1];
	else if (res == 2) cout << s[2];
	else if (res == 3) cout << s[3];
	else if (res == 4) cout << s[4];
	else if (res == 5) cout << s[5];
	else if (res == 6) cout << s[6];
	cout << endl;
	return 0;
}
