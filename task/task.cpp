
#include "task.h"

int fibonacchi(int n)
{
	return (n < 3) ?  
		1 : 
		fibonacchi(n-1) + fibonacchi(n-2);
}

