
#include "task.h"

int fibonacchi(int n)
{
	return (n < 3) ?  
		1 : 
		fibonacchi(n-1) + fibonacchi(n-2);
}

int IsPrime(int n)
{
    if (n < 2)
        return false;

    int retVal = 1;
    for (int i = 2; i < n/2; ++i)
    {
        if (n%i == 0)
        {
            retVal = 0;
            break;
        }
    }

    return retVal;
}


