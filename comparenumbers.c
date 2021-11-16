#include <stdio.h>
int main(void)
{
	printf("%d", test(1,2));
	printf("\n%d", test(2,2));
}
int test(int x, int y)
//This creates another function, using parameters x and y and defining them within
//the creation of said function.
{
	return x == y ? (x + y)*3 : x + y;
	//this works by only returning if x == y, which in the case of test(2,2) is true
	//so therefore the only outputs in this program are 3 and 12 as 1+2 = 3 and
	//because if x == y the program triples the sum of x and y, (2+2)*3 = 12
	//so this return here is saying, if x == y, then return (x+y)*3, otherwise
	//return just  x + y
}
	
