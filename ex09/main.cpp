#include "vectorialLib.hpp"

using namespace ft;

int main()
{

	Matrix<int> a = {
			{0, 2, 3, 4, 5},
			{3, 1, 4, 6, -1},
			{-7, 1, 2, 3, 4},
			{0, 0, 0, 0, 0},
			{10, 10, 10 ,10 ,10}
	};

	Matrix<int> b = {
			{-2, -8, 4},
			{1, -23, 4},
			{0, 6, 4}
	};

	Matrix<int> c = {
			{1, 2, 3},
			{4, 5, 6}
	};

	std::cout << "transposed of \n" << a << "\n = \n" << a.transpose() << '\n';
	std::cout << "transposed of \n" << b << "\n = \n" << b.transpose() << '\n';
	std::cout << "transposed of \n" << c << "\n = \n" << c.transpose() << '\n';
	return 0;
}