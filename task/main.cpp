#include "task.h"

int main(int argc, char** argv)
{
	if (argc < 2)
		return 1;

	std::string str = argv[1];

	int num;
	std::istringstream ( str ) >> num;
	
	int res = fibonacchi(num);

	printf("Res: %d\n", res);

	int prime = IsPrime(num);
	
	printf("Res2: %d\n", prime);

	return 0;
}


