#include "cpu-utils.h"
#include "lib-utils.h"
 
int foo1(int a, int b)
{
    int c;    
	c = a + b;
	return c;
}

long foo2(int a, int b)
{
    long c;    
	c = a * b;
	return c;
}
	int a=0x11111111; int b=0x22222222; 
	int x=0x33333333;	
	long y=0;
	
int main()
{

	x = foo1(a,b);
	y=foo2(a,b);
	while(1);
	return 0;
}
