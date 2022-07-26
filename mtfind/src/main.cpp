#include "mtfind.h"

int main(int argc, char* argv[])
{
	if (argc < 3 || argc > 3)
	{
		std::cout << "Wrong parameters!" << std::endl;
		return -1;
	}
	else
	{
		if (argv[2][0] != '?' || strlen(argv[2]) <= 1)
		{
			std::cout << "Wrong mask!" << std::endl;
			return -2;
		}
	}

	mtfind mtfind(argv[1], argv[2]);
	mtfind.find();

	return 0;
}