#include "vectorialLib.hpp"

using namespace ft;

int main()
{

	Matrix<int> a(3, 6, 2);
	Matrix<int> b(6, 3, 2);

	Matrix<int> c = a * b;

	std::cout << "a = \n" << a << '\n';
	std::cout << "b = \n" << b << '\n';
	std::cout << "c = \n" << c << '\n';
	std::cout << "trace a : " << a.trace() << '\n';
	std::cout << "trace c : " << c.trace() << '\n';

	a = {
			{0, 2, 3, 4, 5},
			{3, 1, 4, 6, -1},
			{-7, 1, 2, 3, 4},
			{0, 0, 0, 0, 0},
			{10, 10, 10 ,10 ,10}
	};

	b = {
			{-2, -8, 4},
			{1, -23, 4},
			{0, 6, 4}
	};

	std::cout << "trace of \n" << a << " = " << a.trace() << '\n';
	std::cout << "trace of \n" << b << " = " << b.trace() << '\n';
	return 0;
}