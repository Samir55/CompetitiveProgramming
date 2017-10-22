#include <iostream>
using namespace std;
int main() {
int n, h;
int res = 0;
int hs;
cin >> n >> h;
for(int i = 0; i < n; i++)
{
	cin >> hs;
	if (hs <= h)
	res += 1;
	else 
	res += 2;  
}
cout << res << endl;
return 0;
}
