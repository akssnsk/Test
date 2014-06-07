#include "task.h"

int main(int argc, char** argv)
{
	std::string str = argv[1];

	int num;
	std::istringstream ( str ) >> num;
	
	int res = fibonacchi(num);

	printf("Res: %d\n", res);

	return 0;
}


