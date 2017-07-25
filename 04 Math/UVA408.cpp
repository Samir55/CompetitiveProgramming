#include <iostream>
#include <stdio.h>
using namespace std;
int step, mode;
int GCD(int u, int v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main(){
	while( scanf("%d %d", &step, &mode) != EOF) 
	{
		if (GCD(step, mode) == 1)
			printf("%10d%10d    Good Choice\n", step, mode);
		else
			printf("%10d%10d    Bad Choice\n", step, mode);
			printf("\n");
			
	}
	return 0;
}
