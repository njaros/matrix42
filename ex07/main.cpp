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

std::cout << "\n>>subject exemples<<\n\n";

	Matrix j({{1, 0}, {0, 1}});
	Matrix k({{4, 2}});

	std::cout << k * j << "\n\n";

	j = {{2, 0}, {0, 2}};
	k = {{4, 2}};
	std::cout << k * j << "\n\n";

	j = {{2, -2}, {-2, 2}};
	k = {{4, 2}};
	std::cout << k * j << "\n\n";

	j = {{1, 0}, {0, 1}};
	k = {{1, 0}, {0, 1}};
	std::cout << k * j << "\n\n";

	j = {{1, 0}, {0, 1}};
	k = {{2, 1}, {4, 2}};
	std::cout << k * j << "\n\n";

	j = {{3, -5}, {6, 8}};
	k = {{2, 1}, {4, 2}};
	std::cout << k * j << "\n\n";

	return 0;
}