#include "../includes/vectorialLib.hpp"

using namespace ft;

void	displayFormat(double d)
{
	long l = d;

	std::cout << d;
	d -= l;

	if (!d)
	std::cout << '.';
}

int main()
{

	Matrix m = projection(90., 1., 1., 100.);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			displayFormat(m[i][j]);
			if (j < 3)
				std::cout << ", ";
		}
		std::cout << '\n';
	}
	return 0;
}