#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{

	Matrix<float>	a({
							   {2, 0, 0},
							   {0, 2, 0},
							   {0, 0, 2}
	});

	a.displayMatrixLn();
	std::cout << "rank = " << a.rank() << "\n\n";

	Matrix<float>	b({
							   {1, 0, 0},
							   {0, 1, 0},
							   {0, 0, 1}
	});

	b.displayMatrixLn();
	std::cout << "rank = " << b.rank() << "\n\n";

	Matrix<float>	c({
							   {8, 5, -2},
							   {4, 7, 20},
							   {7, 6, 1}
	});

	c.displayMatrixLn();
	std::cout << "rank = " << c.rank() << "\n\n";

	Matrix<float>	d({
							   {1, 2, 3},
							   {4, 5, 6}
	});

	d.displayMatrixLn();
	std::cout << "rank = " << d.rank() << "\n\n";

	Matrix<float>	e = {
			{8, 5, -2, 4},
			{4, 2.5, 20, 4},
			{8, 5, 1, 4},
			{28, -4, 17, 1}
	};

	e.displayMatrixLn();
	std::cout << "rank = " << e.rank() << "\n\n";

	Matrix<float>	f = {
			{7, 4, 1},
			{1, 0, 0},
			{14, 8, 2}
	};

	f.displayMatrixLn();
	std::cout << '\n';
	f.triangular().displayMatrixLn();
	std::cout << "rank = " << f.rank() << "\n\n";

	Matrix<float>	g = {
			{8, 5, -2},
			{4, 7, 20},
			{7, 6, 1},
			{21, 18, 7}
	};

	g.displayMatrixLn();
	std::cout << '\n';
	g.triangular().displayMatrixLn();
	std::cout << "rank = " << g.rank() << '\n';
	return 0;
}