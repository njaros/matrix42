#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{

	Matrix<int> a(2, 6, 2);
	Matrix<int> b(6, 3, 2);

	Matrix<int> c = a * b;

	std::cout << "a = \n" << a << '\n';
	std::cout << "b = \n" << b << '\n';
	std::cout << "c = \n" << c << '\n';

	a = {
			{3, -5},
			{6, 8}
	};
	b = {
			{2, 1},
			{4, 2}
	};

	c = a * b;
	std::cout << "a = \n" << a << '\n';
	std::cout << "b = \n" << b << '\n';
	std::cout << "c = \n" << c << '\n';

	Vector<int> v({4, 2});
	Matrix<int>	m({
							 {2, 0},
							 {0, 2}
	});

	Vector<int> u(v * m);
	std::cout << u << '\n';
	u = (m * v);
	std::cout << u << '\n';

	v = {1, 2, 3, 4};
	m = {
			{2, 3, 0, 1},
			{1, 1, 1, 1},
			{0, 0, 0, 0}
	};

	u = m * v;

	std::cout << u << '\n';

	return 0;
}