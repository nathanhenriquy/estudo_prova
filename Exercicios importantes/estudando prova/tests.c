#include <stdio.h> 

int main( void ) { 
	int x, *p, **q; 
	p = &x; 
	q = &p; 
	x = 10; 
	printf("%d\n", &q); 
}